class Node:
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

def find_lca(root, n1, n2):
    if root is None:
        return None

    if root.val == n1 or root.val == n2:
        return root

    left_lca = find_lca(root.left, n1, n2)
    right_lca = find_lca(root.right, n1, n2)

    if left_lca and right_lca:
        return root

    return left_lca if left_lca else right_lca

# Example usage
root = Node(3)
root.left = Node(5)
root.right = Node(1)
root.left.left = Node(6)
root.left.right = Node(2)
root.right.left = Node(0)
root.right.right = Node(8)
root.left.right.left = Node(7)
root.left.right.right = Node(4)

n1, n2 = 7, 4
lca = find_lca(root, n1, n2)
if lca:
    print(f"LCA of {n1} and {n2} is {lca.val}")
else:
    print("LCA not found")
