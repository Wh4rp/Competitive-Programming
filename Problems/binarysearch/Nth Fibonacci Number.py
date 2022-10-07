class Solution:
    def solve(self, n):
        a, b = 1, 1
        for i in range(n-2):
            a, b = b, a+b
        return b