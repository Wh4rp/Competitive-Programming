class Solution:
    def solve(self, nums):
        n = len(nums)
        pos = [-2] * (n + 5)
        pos[0], ac, ans = -1, 0, 0
        for i in range(n):
            ac += nums[i]
            if pos[ac] == -2:
                pos[ac] = i
            else:
                ans = max(ans, i - pos[ac])
        return ans