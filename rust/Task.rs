use rayon::prelude::*;
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

#[derive(Debug)]
struct Task {
    id: usize,
    duration: Duration,
}

impl Task {
    fn new(id: usize, duration: Duration) -> Self {
        Task { id, duration }
    }

    fn execute(&self) {
        println!("Executing task {} with duration {:?}", self.id, self.duration);
        thread::sleep(self.duration);
        println!("Completed task {}", self.id);
    }
}

#[derive(Debug)]
struct Scheduler {
    tasks: Arc<Mutex<Vec<Task>>>,
}

impl Scheduler {
    fn new() -> Self {
        Scheduler {
            tasks: Arc::new(Mutex::new(Vec::new())),
        }
    }

    fn add_task(&self, task: Task) {
        let mut tasks = self.tasks.lock().unwrap();
        tasks.push(task);
    }

    fn execute_tasks(&self) {
        let tasks = self.tasks.lock().unwrap();
        tasks.par_iter().for_each(|task| {
            task.execute();
        });
    }
}

fn main() {
    let scheduler = Scheduler::new();

    for i in 0..5 {
        scheduler.add_task(Task::new(i, Duration::from_secs(i as u64)));
    }

    scheduler.execute_tasks();
}
