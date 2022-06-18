class Solution:
    def solve(self, s):
        return abs(s.count('L') - s.count('R')) + s.count('?')