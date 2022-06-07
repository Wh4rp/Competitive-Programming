class Solution:
  def solve(self, nums):
    n = len(nums)
    m = len(set(nums))
    if n != m:
      return False
    nums1 = sorted(nums)
    nums2 = sorted(nums, reverse=True)
    return (nums == nums1) or (nums == nums2)