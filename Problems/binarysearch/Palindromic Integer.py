class Solution:
  def solve(self, num):
    num_aux = num
    n = 0
    while num_aux:
      num_aux //= 10
      n += 1
    while num:
      if num % 10 != num // 10**(n - 1):
        return False
      num = (num % 10**(n - 1)) // 10
      n -= 2
    return True