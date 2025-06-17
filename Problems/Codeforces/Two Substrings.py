s = input()

# buscamos AB y despues BA

i = s.find("AB")

if i != -1:
    j = s[i+2:].find("BA")
    if j != -1:
        print("YES")
        exit()

# buscamos BA y despues AB

i = s.find("BA")

if i != -1:
    j = s[i+2:].find("AB")
    if j != -1:
        print("YES")
        exit()

print("NO")