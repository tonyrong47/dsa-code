import asyncio
import inspect
from typing import Callable, List, Any

# Metaclass to automatically register tasks
class TaskMeta(type):
    registry = []

    def __new__(cls, name, bases, attrs):
        new_class = super().__new__(cls, name, bases, attrs)
        if 'run' in attrs and callable(attrs['run']):
            TaskMeta.registry.append(new_class)
        return new_class

# Base Task
class Task(metaclass=TaskMeta):
    async def run(self, data: Any) -> Any:
        raise NotImplementedError

# Example Tasks
class TaskA(Task):
    async def run(self, data: Any) -> Any:
        await asyncio.sleep(1)
        print(f"TaskA processed: {data}")
        return f"{data} -> TaskA"

class TaskB(Task):
    async def run(self, data: Any) -> Any:
        await asyncio.sleep(1)
        print(f"TaskB processed: {data}")
        return f"{data} -> TaskB"

class TaskC(Task):
    async def run(self, data: Any) -> Any:
        await asyncio.sleep(1)
        print(f"TaskC processed: {data}")
        return f"{data} -> TaskC"

# Pipeline Runner
class Pipeline:
    def __init__(self, tasks: List[Callable]):
        self.tasks = tasks

    async def run(self, initial_data: Any):
        data = initial_data
        for task_cls in self.tasks:
            task = task_cls()
            data = await task.run(data)
        return data

# Dynamic Pipeline Creation
async def main():
    print("Registered Tasks:", [cls.__name__ for cls in TaskMeta.registry])
    pipeline = Pipeline(TaskMeta.registry)
    result = await pipeline.run("Start")
    print("Pipeline Result:", result)

if __name__ == "__main__":
    asyncio.run(main())
