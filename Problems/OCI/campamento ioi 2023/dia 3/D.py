dp = []
for i in range(255):
    dp.append([-1] * 55)
coins = []
def getWays(c, i):
    if c == 0:
        return 1
    elif c < 0:
        return 0
    elif i > len(coins) - 1:
        return 0
    elif dp[c][i] != -1:
        return dp[c][i]
    else:
        ans = getWays(c - coins[i], i) + getWays(c, i+1)
        dp[c][i] = ans
        return ans

n, m = input().split(' ')
n = int(n)
m = int(m)
coins = list(map(int, input().split(' ')))
print(getWays(n, 0))