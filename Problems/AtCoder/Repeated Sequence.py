# Python solution for the given problem
# This script determines if a sum S exists in a periodic sequence A

def has_subsequence_sum(N, S, A):
    prefix_sums = {0}
    current_sum = 0

    for _ in range(min(S // min(A), N + 1)):
        for num in A:
            current_sum += num
            if current_sum - S in prefix_sums:
                return True
            prefix_sums.add(current_sum)

    return False

# Input reading and function call
import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
S = int(data[1])
A = list(map(int, data[2:]))

if has_subsequence_sum(N, S, A):
    print("Yes")
else:
    print("No")