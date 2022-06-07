class Solution:
  def solve(self, s):
    ant = ""
    cont = ""
    sol = ""
    for i in s:
      if i != ant:
        sol += str(cont) + ant
        ant = i
        cont = 1
      else:
        cont += 1
    sol += str(cont) + ant
    return sol