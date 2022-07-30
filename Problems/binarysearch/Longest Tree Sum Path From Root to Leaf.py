# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        def dfs(node):
            if node:
                left = dfs(node.left)
                right = dfs(node.right)
                depth, sum = max(left, right)
                return (depth + 1, sum + node.val)
            else:
                return (0, 0)
        return dfs(root)[1]