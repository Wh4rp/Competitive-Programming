# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, a, b):
        if root:
            if root.val == a or root.val == b:
                return root.val
            left = self.solve(root.left, a, b)
            right = self.solve(root.right, a, b)
            if left and right:
                return root.val
            return left or right