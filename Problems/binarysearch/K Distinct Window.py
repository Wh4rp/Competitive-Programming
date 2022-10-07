class Solution:
    def solve(self, nums, k):
        n, count, repeted = len(nums), 0, []
        m = [0] * 100005
        for i in nums[:k]:
            m[i] += 1
            count += (m[i]==1)
        repeted.append(count)
        for i in range(k, n):
            m[nums[i]] += 1
            count += (m[nums[i]]==1)
            m[nums[i-k]] -= 1
            count -= (m[nums[i-k]]==0)
            repeted.append(count)
        return repeted