def primes():
    primes = []
    x = 2
    while True:
        is_prime = True
        for i in primes:
            if x % i == 0:
                is_prime = False
        if is_prime:
            primes.append(x)
            yield x
        x += 1

cont = 0
for i in primes():
    cont += 1
    if(cont == 10001):
        print(i)
        break
