for i in range(1, 1001):
    for j in range(i + 1, 1001):
        for k in range(j + 1, 1001):
            if i + j + k == 1000 and i ** 2 + j ** 2 == k ** 2:
                print(i * j * k)
                break
            elif i + j + k > 1000:
                break
            else:
                continue