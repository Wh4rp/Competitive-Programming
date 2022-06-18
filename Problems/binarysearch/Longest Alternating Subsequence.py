class Solution:
    def solve(self, nums):
        if not nums: return 0
        difs = [(i - j) // abs(i - j) for i, j in zip(nums, nums[1:]) if i != j]
        sol = [k for k, g in groupby(difs)]
        return len(sol) + 1