class Solution:
  def solve(self, nums, k):
    n = len(nums)
    nums.sort()
    i = 0
    j = n - 1
    while i < j:
      if nums[i] + nums[j] == k:
        return True
      elif nums[i] + nums[j] < k:
        i+=1
      else:
        j-=1
    return False