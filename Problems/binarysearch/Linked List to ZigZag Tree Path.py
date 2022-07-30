# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# class LLNode:
#     def __init__(self, val, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def solve(self, node):
        if node:
            nodeT = Tree(node.val)
            if node.next:
                if node.val > node.next.val:
                    nodeT.left = self.solve(node.next)
                else:
                    nodeT.right = self.solve(node.next)
            return nodeT