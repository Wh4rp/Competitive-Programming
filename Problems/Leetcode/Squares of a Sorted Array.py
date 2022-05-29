class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        squares = []
        j = 0
        while j < len(nums) and nums[j] < 0:
            j+= 1
        i = j - 1
        while 0 <= i and j < len(nums):
            if nums[i]**2 < nums[j]**2:
                squares.append(nums[i]**2)
                i -=1
            else:
                squares.append(nums[j]**2)
                j +=1
                
        while j < len(nums):
            squares.append(nums[j]**2)
            j +=1
        while 0 <= i:
            squares.append(nums[i]**2)
            i-= 1
        return squares