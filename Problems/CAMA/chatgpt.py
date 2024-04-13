def minimum_minutes_to_reach_weight(n):
    minutes = 0
    discs = []
    
    while n > 1:
        discs.append(n)
        n = (n + 1) // 2
        minutes += 1
    
    return minutes, discs

# Input
n = int(input())

# Calculate minimum minutes and the sequence of discs
minutes, discs = minimum_minutes_to_reach_weight(n)

# Output
print(minutes)
print(*discs)
