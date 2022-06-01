class Solution:
  def solve(self, matrix):
    n = len(matrix)     # number rows
    m = len(matrix[0])  # number cols
    ans = n * m
    rows = [1] * n
    cols = [1] * m
    rows_safe = n
    cols_safe = m
    for i in range(n):
      for j in range(m):
        if matrix[i][j] == 1:
          if rows[i]:
            rows_safe -= 1
            rows[i] = 0
          if cols[j]:
            cols_safe -= 1
            cols[j] = 0
    return rows_safe * cols_safe