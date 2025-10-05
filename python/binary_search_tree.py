class Node:
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.val:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

def search(root, key):
    if root is None or root.val == key:
        return root
    if key < root.val:
        return search(root.left, key)
    return search(root.right, key)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=' ')
        inorder(root.right)

# Example usage
root = None
keys = [20, 10, 30, 5, 15, 25, 35]

for key in keys:
    root = insert(root, key)

print("Inorder traversal of BST:")
inorder(root)
print()

search_key = 15
result = search(root, search_key)
if result:
    print(f"Found {search_key} in BST")
else:
    print(f"{search_key} not found in BST")
