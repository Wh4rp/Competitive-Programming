# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        def all_numbers(node):
            if not node:
                return []
            else:
                numbers = all_numbers(node.left) + all_numbers(node.right)
                if not len(numbers):
                    numbers = [str(node.val)]
                else:
                    numbers = [str(node.val) + i for i in numbers]
                print(numbers)
                return numbers
        list_numbers = all_numbers(root)
        suma = 0
        print(list_numbers)
        for i in list_numbers:
            suma += int(i)
        return suma
