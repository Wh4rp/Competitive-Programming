class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        stepsDP = [0] * n
        stepsDP[0] = nums[0]
        for i in range(1, n):
            if stepsDP[i - 1] < i:
                return False
            stepsDP[i] = max(stepsDP[i - 1], i + nums[i])
        return True