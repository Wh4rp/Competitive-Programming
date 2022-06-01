class Solution:
  def solve(self, nums):
    n = len(nums)
    for i in range(2, n, 4):
      aux = nums[i] 
      nums[i] = nums[i - 2]
      nums[i - 2] = aux
    for i in range(3, n, 4):
      aux = nums[i] 
      nums[i] = nums[i - 2]
      nums[i - 2] = aux
      
      return nums