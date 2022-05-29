class Solution:
    def tribonacci(self, n: int) -> int:
        fib_list = [0, 1, 1]
        for i in range(3, n + 1):
            fib_list.append(fib_list[i - 1] + fib_list[i - 2] + fib_list[i - 3])
        return fib_list[n]