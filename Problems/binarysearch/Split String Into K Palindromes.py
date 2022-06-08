class Solution:
    def solve(self, s, k):
        n = len(s)
        memo = [[-1] * (105) for _ in range(105)]

        def count_pal(a):
            cont = 0
            for i in range(len(a)//2):
                if a[i] != a[-i-1]:
                    cont += 1
            #print(f"Se cuenta al {a} y es {cont}")
            return cont

        def dp(i, j):
            if j == 1:
                return count_pal(s[:i+1])
            if memo[i][j] != -1:
                return memo[i][j]
            ans = 105
            k = 1
            while i - k >= 0:
                ans = min(ans, dp(i - k, j-1) + count_pal(s[i - k + 1:i + 1]))
                k += 1
            memo[i][j] = ans
            return ans
        return dp(n-1, k)