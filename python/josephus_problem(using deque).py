#Josephus problem implementation using queue!
#Josephus problem:The Josephus Problem is a mathematical counting-out game where people stand in a circle and are eliminated one by one until only one remains, with the goal of finding the starting position of the last survivor. Named after the historian Flavius Josephus, it involves eliminating every kth person in a circle of n people, with the challenge being to determine the starting position that guarantees survival.

#CODE
#double ended queue based opearations
class Deque:
    def __init__(self):
        self.items = []

    def append(self, item):
        self.items.append(item)

    def popleft(self):
        if self.items:
            return self.items.pop(0)
        return None

    def rotate(self, n):
        n = n % len(self.items)  # handle n > length
        self.items = self.items[n:] + self.items[:n]

    def __len__(self):
        return len(self.items)

    def front(self):
        return self.items[0] if self.items else None

#solution for josephus
def josephus_queue(n, k):
    q = Deque()
    for i in range(1, n + 1):
        q.append(i)
    while len(q) > 1:
        q.rotate(k - 1)
        q.popleft()
    return q.front()

#sample to test
'''n = 7
k = 3
survivor = josephus_queue(n, k)
print("The survivor is at position:", survivor)'''
