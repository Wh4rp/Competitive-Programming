# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        if root:
            return root.val + self.solve(root.left) + self.solve(root.right)
        else:
            return 0