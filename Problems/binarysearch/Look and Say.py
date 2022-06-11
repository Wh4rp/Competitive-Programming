class Solution:
    def solve(self, n):
        s = "1"
        for _ in range(n - 1):
            s_tmp = ""
            for x, y in groupby(s):
                s_tmp += f"{len(list(y))}{x}"
            s = s_tmp
        return s