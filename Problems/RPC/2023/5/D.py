x = input()
left = "qwertasdfgzxcvb"
right = "yuiophjklnm"

left_ver = True
right_ver = True

for i in range(len(x)):
    if i % 2 == 0:
        if x[i] not in left:
            left_ver = False
            break
    else:
        if x[i] not in right:
            left_ver = False
            break


for i in range(len(x)):
    if i % 2 == 0:
        if x[i] not in right:
            right_ver = False
            break
    else:
        if x[i] not in left:
            right_ver = False
            break

if (left_ver or right_ver):
    print("yes")
else:
    print("no")
