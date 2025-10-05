
from collections import deque

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree_level_order(values):
    if not values:
        return None
    it = iter(values)
    root_val = next(it)
    if root_val is None:
        return None

    root = Node(root_val)
    q = deque([root])

    for v in it:
        parent = q[0]
        if parent.left is None:
            if v is not None:
                parent.left = Node(v)
                q.append(parent.left)
            else:
                parent.left = None
            continue
        if parent.right is None:
            if v is not None:
                parent.right = Node(v)
                q.append(parent.right)
            else:
                parent.right = None
            q.popleft()
    return root

if __name__ == "__main__":
    vals = [1, 2, 3, 4, 5, None, 7]
    root = build_tree_level_order(vals)
