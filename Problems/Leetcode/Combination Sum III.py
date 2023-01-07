class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        ans = []
        self.backtraking(k, 1, n, [], ans)
        return ans
    
    def backtraking(self, k, t, n, v, ans):
        if n < 0:
            return []
        elif k == 0:
            if n == 0:
                ans.append(v)
        else:
            if t < 10:
                self.backtraking(k, t+1, n, v, ans)
                self.backtraking(k-1, t+1, n-t, v + [t], ans)

if __name__ == '__main__':
    s = Solution()
    print(s.combinationSum3(3, 9))