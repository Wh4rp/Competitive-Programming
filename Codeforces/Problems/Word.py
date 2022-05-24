w = input()
cont = 0
for i in w:
    if i.lower() == i:
        cont+=1
if 2 * cont >= len(w):
    print(w.lower())
else:
    print(w.upper())