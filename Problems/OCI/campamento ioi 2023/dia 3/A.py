dp = []

for i in range(505):
    dp.append([0] * 505)

def build(l, b):
    if dp[l][b]:
        return dp[l][b]
    elif b == 0:
        return 1
    elif b < 0:
        return 0
    else:
        count = 0
        for i in range(l, b + 1):
            count += build(i+1, b - i)
        dp[l][b] = count
        return dp[l][b]

n = int(input())
print(build(1, n) - 1)
