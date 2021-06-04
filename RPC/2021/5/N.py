n = int(input())
s = input()
aux = 1
d = 1
string = ""
for i in range(1, 101): 
    string += str(i)
# print(string)

for i in range(len(s)):
    if i+len(str(aux)) > len(s) or s[i : i+len(str(aux))] != str(aux):
        print(s[i: i+len(str(aux))])
        print(aux)
        break

    i += len(str(aux)) 
    print(aux, 'inicio en ',i)
    aux += 1