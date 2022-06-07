class Solution:
  def solve(self, s):
    charactes = []
    for i in s:
      if i in charactes:
        return False
      charactes.append(i)
    return True