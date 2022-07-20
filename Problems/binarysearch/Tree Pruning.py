# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        def prune(node):
            if node is None: return False
            node.left = None if prune(node.left) else node.left
            node.right = None if prune(node.right) else node.right
            return node.left is None and node.right is None and node.val == 0
        prune(root)
        return root