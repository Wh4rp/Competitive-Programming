# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, lo, hi):
        def dfs(node):
            if node:
                left = dfs(node.left)
                right = dfs(node.right)
                return left + right + (lo <= node.val <= hi)
            else:
                return 0
        return dfs(root)
