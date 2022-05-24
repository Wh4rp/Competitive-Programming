class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n > 1:
            NumsDP1 = [nums[0], max(nums[0], nums[1])]
            for i in range(2, n - 1):
                NumsDP1.append(max(nums[i] + NumsDP1[i - 2], NumsDP1[i - 1]))
            if n > 2:
                NumsDP2 = [nums[1], max(nums[1], nums[2])]
                for i in range(3, n):
                    NumsDP2.append(max(nums[i] + NumsDP2[i - 3], NumsDP2[i - 2]))
                return max(NumsDP1[n-2], NumsDP2[n-2])
            else:
                return NumsDP1[n-1]
        else:
            return nums[0]
