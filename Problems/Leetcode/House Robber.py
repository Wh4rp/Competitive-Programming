class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n > 1:
            NumsDP = [nums[0], max(nums[0], nums[1])]
            for i in range(2, n):
                NumsDP.append(max(nums[i] + NumsDP[i - 2], NumsDP[i - 1]))
            return NumsDP[n-1]
        else:
            return nums[0]
