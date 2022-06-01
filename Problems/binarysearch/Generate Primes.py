class Solution:
  def solve(self, n):
    primes = [i for i in range(3, n + 1, 2)]
    if 2 <= n:
      primes = [2] + primes
    for i in primes:
      for j in range(i * i, n + 1, i):
        if j in primes:
          primes.remove(j)
    return primes