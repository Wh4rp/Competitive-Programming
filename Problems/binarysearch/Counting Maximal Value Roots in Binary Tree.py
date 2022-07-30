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
                if max(left, right) <= node.val:
                    self.ans += 1
                return max(left, right, node.val)
            else:
                return -1
        self.ans = 0
        dfs(root)
        return self.ans