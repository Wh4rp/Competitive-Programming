class Solution:
  def solve(self, n):
    sol = []
    for i in range(1, n + 1):
      if i%3 == 0 or '3' in str(i) or '6' in str(i) or '9' in str(i):
        sol.append("clap")
      else:
        sol.append(str(i))
    return sol