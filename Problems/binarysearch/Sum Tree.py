# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        if root and (root.left or root.right):
            val_left = root.left.val if root.left else 0
            val_right = root.right.val if root.right else 0
            return root.val == val_left + val_right and self.solve(root.left) and self.solve(root.right)
        else:
            return True