def to_binary(n):
  x = ""
  while n != 0:
    if n % 2 != 0:
      x = "1" + x
    else:
      x = "0" + x
    n //= 2
  return x

def from_binary(n):
  x = 0
  pow = 1
  for i in n[::-1]:
    if int(i) % 2 != 0:
      x += pow
    pow *= 2
  return x

n = int(input())
print(from_binary(to_binary(n)[::-1]))