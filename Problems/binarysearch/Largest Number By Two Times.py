class Solution:
  def solve(self, nums):
    nums.sort()
    return 2*nums[-2] < nums[-1]