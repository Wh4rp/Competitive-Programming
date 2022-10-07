class Solution:
    def solve(self, ip):
        def valid(nums):
            for i in nums:
                if int(i) > 255 or (i[0] == '0' and int(i) != 0):
                    return False
            return True

        ans = []
        n = len(ip)
        for i in range(1, n):
            for j in range(i+1, min(n, i+4)):
                for k in range(j+1, min(n, j+4)):
                    if valid([ip[:i], ip[i:j], ip[j:k], ip[k:]]):
                        ans.append(ip[:i] + '.' + ip[i:j] + '.' + ip[j:k] + '.' + ip[k:])
        return ans