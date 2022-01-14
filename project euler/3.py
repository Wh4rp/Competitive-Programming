n = 600851475143
k = 1

while n > 1:
    k += 1
    while n % k == 0:
        n /= k

print(k)
