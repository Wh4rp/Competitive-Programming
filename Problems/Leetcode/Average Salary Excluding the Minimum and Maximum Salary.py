class Solution:
    def average(self, salary: List[int]) -> float:
        salary.sort()
        ans = 0
        for i in salary[1:-1]:
            ans += i
        return ans / (len(salary) - 2)