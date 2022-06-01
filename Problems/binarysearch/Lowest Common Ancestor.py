# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
	def solve(self, root, a, b):
		Union = [root.val]
		if root.left is not None:
			Left = self.solve(root.left, a, b)
			if type(Left) is int:
					return Left
			Union += Left
		if root.right is not None:
			Right = self.solve(root.right, a, b)
			if type(Right) is int:
					return Right
			Union += Right
		if a in Union and b in Union:
			return root.val
		else:
			return Union