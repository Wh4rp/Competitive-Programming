class Solution:
  def solve(self, s):
    def prox(i, s):
      j = i + 1
      while j < len(s) and s[i] == s[j]:
        j += 1
      return j
    sol = ""
    i = 0
    while i < len(s):
      sol += s[i]
      i = prox(i, s)
    return sol
