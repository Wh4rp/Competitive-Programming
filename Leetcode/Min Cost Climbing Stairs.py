class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        cost.append(0)
        CostsDP = cost[0:2]
        for i in range(2, n + 1):
            CostsDP.append(cost[i] + min(CostsDP[i - 1], CostsDP[i -2]))
        return CostsDP[n]