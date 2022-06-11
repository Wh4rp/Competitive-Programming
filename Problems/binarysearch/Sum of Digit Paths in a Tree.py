# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        def sum_tree(node, val):
            if not node:
                return 0
            val = val * 10 + node.val
            if not node.left and not node.right:
                return val
            else:
                return sum_tree(node.left, val) + sum_tree(node.right, val)
        ans = sum_tree(root, 0)
        return ans
