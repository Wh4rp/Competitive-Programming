class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        points = [0] * (10**4 + 1)
        for i in nums:
            points[i] += i
        NumsDP = [points[0], max(points[0], points[1])]
        
        for i in range(2, 10**4 + 1):
            NumsDP.append(max(points[i] + NumsDP[i - 2], NumsDP[i - 1]))
        
        return NumsDP[10**4]