def eliminador(s, t):
    i = 0
    j = 0
    cnt = 1
    while i < len(s) and j < len(t):
        if s[i] != t[j]:
            if cnt == 1:
                j += 1
                cnt -= 1
            else:
                print("No")
                return
        else:
            i += 1
            j += 1

    print("Yes")

if __name__ == "__main__":
    k = int(input())
    s = input()
    t = input()

    if len(s) == len(t):
        if s == t:
            print("Yes")
        else:
            cnt = 0
            for i in range(len(s)):
                cnt += s[i] != t[i]
            if cnt == 1:
                print("Yes")
            else:
                print("No")
    else:
        if len(s) + 1 == len(t):
            eliminador(s, t)
        elif len(s) == len(t) + 1:
            eliminador(t, s)
        else:
            print("No")
