class Solution:
    def solve(self, matrix):
        def dis(a, b):
            return abs(a[0]-b[0]) + abs(a[1]-b[1]) - 1
        
        def dfs(i, j, k):
            if 0 <= i < n and 0 <= j < m and matrix[i][j] == 1:
                matrix[i][j] = k
                self.sets[k-2].append((i,j))
                dfs(i+1, j, k)
                dfs(i, j+1, k)
                dfs(i-1, j, k)
                dfs(i, j-1, k)

        n, m = len(matrix), len(matrix[0])
        k = 2
        self.sets = [[],[]]
        for i, j in product(range(n),range(m)):
            if  matrix[i][j] == 1:
                dfs(i, j, k)
                k += 1
        
        ans = 1000
        for x, y in product(self.sets[0], self.sets[1]):
            ans = min(ans, dis(x, y))
        return ans