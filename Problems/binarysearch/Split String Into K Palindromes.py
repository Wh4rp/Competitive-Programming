class Solution:
    def solve(self, s, k):
        def count_pal(a):
            return sum([a[i] != a[~i] for i in range(len(a) // 2)])
        
        @cache
        def dp(i, j):
            if j == 1:
                return count_pal(s[:i+1])
            ans = 105
            k = 1
            while i - k >= 0:
                ans = min(ans, dp(i - k, j-1) + count_pal(s[i - k + 1:i + 1]))
                k += 1
            return ans
        
        return dp(len(s)-1, k)