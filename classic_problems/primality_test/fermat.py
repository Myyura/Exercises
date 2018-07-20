import random

def power(a, n, p):
    result = 1
    a = a % p
    while n > 0:
        if n % 2 == 1:
            result = (result * a) % p
        n = n // 2
        a = (a * a) % p
    return result

def fermat(n, k):
    # we always assume that n >= 2
    if n <= 3:
        return True
    if n == 4:
        return False

    a = random.randint(2, n - 2)
    for _ in range(0, k):
        if power(a, n - 1, n) != 1:
            return False
    return True