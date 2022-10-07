class Solution:
    def solve(self, s):
        s += "0"
        ans = 0
        aux_count = 0
        for c in s:
            if c == "1":
                aux_count += 1
            else:
                ans += (aux_count)*(aux_count+1)//2
                aux_count = 0
        return ans