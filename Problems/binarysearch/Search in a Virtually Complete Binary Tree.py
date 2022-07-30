# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, target):
        if root:
            if root.val == target:
                return True
            left = self.solve(root.left, target)
            right = self.solve(root.right, target)
            return left or right
        else:
            return False