from functools import reduce

hundred_numers = [i for i in range(1, 101)]

sum_squares = reduce(lambda a, b: a + b**2, hundred_numers)
squares_sum = reduce(lambda a, b: a + b, hundred_numers)**2

solution = squares_sum - sum_squares

print(solution)