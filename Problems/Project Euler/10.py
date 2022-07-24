N = 2*(10**6) + 1
primes = [True] * N
primes[0:2] = False, False
ac = 0
for i in range(2, N):
    if primes[i]:
        ac += i
        for j in range(i*i, N, i):
            primes[j]=False
print(ac)