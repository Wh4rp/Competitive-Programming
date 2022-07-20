# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        def sum_tree(node, val):
            if node:
                val = val * 10 + node.val
                left = sum_tree(node.left, val)
                right = sum_tree(node.right, val)
                return left + right if left + right else val
            else:
                return 0
        return sum_tree(root, 0)