# frozen_string_literal: true

require 'thread'
require 'json'
require 'securerandom'
require 'singleton'

# Job Registry for dynamic job discovery
class JobRegistry
  include Singleton
  attr_reader :jobs

  def initialize
    @jobs = {}
  end

  def register(name, klass)
    @jobs[name.to_sym] = klass
  end

  def get(name)
    @jobs[name.to_sym]
  end
end

# Base Job class
class Job
  def self.inherited(subclass)
    JobRegistry.instance.register(subclass.name.split('::').last, subclass)
  end

  def initialize(args)
    @args = args
  end

  def perform
    raise NotImplementedError, "Jobs must implement the perform method"
  end
end

# Example Jobs
class EmailJob < Job
  def perform
    puts "[EmailJob] Sending email to #{@args['email']}"
    sleep(1) # simulate delay
    puts "[EmailJob] Email sent to #{@args['email']}"
  end
end

class ReportJob < Job
  def perform
    puts "[ReportJob] Generating report #{@args['report_id']}"
    sleep(2)
    puts "[ReportJob] Report #{@args['report_id']} generated"
  end
end

# Thread Pool for concurrency
class ThreadPool
  def initialize(size)
    @size = size
    @queue = Queue.new
    @workers = Array.new(size) { worker_thread }
  end

  def worker_thread
    Thread.new do
      loop do
        job = @queue.pop
        break if job == :shutdown
        job.perform
      end
    end
  end

  def schedule(job)
    @queue << job
  end

  def shutdown
    @size.times { @queue << :shutdown }
    @workers.each(&:join)
  end
end

# Job Scheduler
class JobScheduler
  def initialize(pool_size = 4)
    @pool = ThreadPool.new(pool_size)
  end

  def schedule_job(job_name, args)
    job_class = JobRegistry.instance.get(job_name)
    if job_class
      @pool.schedule(job_class.new(args))
    else
      puts "[Scheduler] Job #{job_name} not found"
    end
  end

  def shutdown
    @pool.shutdown
  end
end

# Dynamic Job Loader (simulate plugin loading)
class JobLoader
  def self.load_jobs
    puts "[Loader] Discovering jobs..."
    # In a real system, dynamically load job files
    [EmailJob, ReportJob].each do |job|
      puts "[Loader] Loaded #{job}"
    end
  end
end

# Example usage
JobLoader.load_jobs
scheduler = JobScheduler.new(3)

jobs = [
  { name: 'EmailJob', args: { 'email' => 'user1@example.com' } },
  { name: 'ReportJob', args: { 'report_id' => SecureRandom.uuid } },
  { name: 'EmailJob', args: { 'email' => 'user2@example.com' } },
]

jobs.each { |job| scheduler.schedule_job(job[:name], job[:args]) }

scheduler.shutdown
puts "All jobs completed."
