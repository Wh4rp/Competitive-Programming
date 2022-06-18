# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        def bt(Node):
            if not Node or (not Node.left and not Node.right):
                return True
            else:
                val_left = Node.left.val if Node.left else 0
                val_right = Node.right.val if Node.right else 0
                return (Node.val == (val_left + val_right)) and bt(Node.left) and bt(Node.right)
        return bt(root)