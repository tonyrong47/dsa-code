from collections import OrderedDict
from typing import Optional
class LRUCache:
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity
    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)
if __name__ == "__main__":
    ops = ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    args = [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

    obj: Optional[LRUCache] = None
    results = []
    for op, arg in zip(ops, args):
        if op == "LRUCache":
            obj = LRUCache(arg[0])
            results.append(None)
        elif op == "put":
            obj.put(arg[0], arg[1])
            results.append(None)
        elif op == "get":
            results.append(obj.get(arg[0]))

    print(results)
