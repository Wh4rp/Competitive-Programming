class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k=k%len(nums)
        nums1 = nums[-k:] + nums[:-k]
        for i in range(len(nums)):
            nums[i] = nums1[i]