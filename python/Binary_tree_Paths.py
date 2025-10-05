class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        res = []
        def dfs(node, path):
            if not node:
                return
            # extend path
            newp = path + str(node.val)
            # if leaf
            if not node.left and not node.right:
                res.append(newp)
            else:
                newp += "->"
                dfs(node.left, newp)
                dfs(node.right, newp)
        dfs(root, "")
        return res
