n = int(input())
a, b = map(int, input().split('-'))
turno = a + b
if turno % 4 == 1 or turno % 4 == 2:
    a, b = b, a
flag = True
if (a > 11 or b > 11) or (a == 11 and b == 11):
    print("error 1")
    flag = False
else:
    for i in range(n - 1):
        a2, b2 = map(int, input().split('-'))
        turno2 = a2 + b2
        if turno2 % 4 == 1 or turno2 % 4 == 2:
            a2, b2 = b2, a2
        if turno > turno2:
            flag = False
            print("error", i+2)
            break
        if turno == turno2 and (a != a2 or b != b):
            flag = False
            print("error", i+2)
            break
        if turno < turno2 and (a > a2 or b > b2):
            flag = False
            print("error", i+2)
            break
        if a == 11 and (b != b2):
            flag = False
            print("error", i+2)
            break
        if b == 11 and (a != a2):
            flag = False
            print("error", i+2)
            break
        a, b = a2, b2

if flag:
    print("ok")