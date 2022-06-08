class Solution:
  def solve(self, n):
      ans = "1"
      for i in range(n - 1):
        ans_aux = ""
        index = 0
        large = 1
        while index < len(ans):
          # print(index, large, "---")
          while index + large <= len(ans) and ans[index] * large == ans[index:index + large]:
            large += 1
          # print(index, large, "---")
          large -= 1
          ans_aux += str(large) + str(ans[index])
          index += large
          large = 1
        ans = ans_aux
        # print("ans = ", ans)
      return ans