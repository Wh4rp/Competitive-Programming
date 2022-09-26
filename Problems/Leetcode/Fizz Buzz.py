class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        list = []
        for i in range(1, n+1):
            aux = ""
            if i%3==0:
                aux += "Fizz"
            if i%5==0:
                aux += "Buzz"
            list.append(aux or str(i))
        return list