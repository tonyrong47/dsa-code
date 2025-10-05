<?php
/**
 * Complex PHP Multi-threaded Task Queue
 *
 * Requires pthreads extension: https://www.php.net/manual/en/book.pthreads.php
 * Install: pecl install pthreads
 */

declare(strict_types=1);

class Task extends Thread
{
    private string $taskName;

    public function __construct(string $taskName)
    {
        $this->taskName = $taskName;
    }

    public function run(): void
    {
        echo "Starting task: {$this->taskName}\n";
        sleep(rand(1, 3)); // Simulate work
        echo "Completed task: {$this->taskName}\n";
    }
}

class TaskQueue
{
    private array $tasks = [];
    private int $maxThreads;
    private array $threads = [];

    public function __construct(int $maxThreads = 4)
    {
        $this->maxThreads = $maxThreads;
    }

    public function addTask(Task $task): void
    {
        $this->tasks[] = $task;
    }

    public function run(): void
    {
        while (!empty($this->tasks) || !empty($this->threads)) {
            // Start new threads if possible
            while (count($this->threads) < $this->maxThreads && !empty($this->tasks)) {
                $task = array_shift($this->tasks);
                $task->start();
                $this->threads[] = $task;
            }

            // Remove finished threads
            foreach ($this->threads as $index => $thread) {
                if (!$thread->isRunning()) {
                    unset($this->threads[$index]);
                }
            }

            usleep(100000); // avoid busy waiting
        }
    }
}

// Example usage
$queue = new TaskQueue(3);

for ($i = 1; $i <= 10; $i++) {
    $queue->addTask(new Task("Task $i"));
}

$queue->run();

echo "All tasks completed.\n";
