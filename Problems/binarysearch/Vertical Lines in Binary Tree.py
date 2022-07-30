# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        def dfs(node, pos):
            if node:
                self.left = min(self.left, pos)
                self.right = max(self.right, pos)
                dfs(node.left, pos - 1)
                dfs(node.right, pos + 1)
        self.left = 0
        self.right = 0
        dfs(root, 0)
        return self.right - self.left + 1