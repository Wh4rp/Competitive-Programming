N = int(input())


ans = []
for i in range(1000):
    x = 2**i

    if 2*x >= N:
        ans.append(N - x)
        break

    ans.append(x)

    
print(len(ans))
print(*sorted(ans))