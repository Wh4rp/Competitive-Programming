class Solution:
    def solve(self, nums):
        n, ans, count = len(nums), 0, 0
        nums.sort()
        for i in range(n-1):
            if nums[i+1] - nums[i] == 1:
                count += 1
            if nums[i+1] - nums[i] > 1:
                count = 0
            ans = max(ans, count)
        return ans + 1 if nums else 0