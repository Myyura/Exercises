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

def test(d, n):
    a = random.randint(2, n - 2)
    r = power(a, d, n)
    if r == 1 or r == n - 1:
        return True
    
    while d != n - 1:
        r = (r * r) % n
        d *= 2
        if r == 1:
            return False
        if r == n - 1:
            return True
    
    return False

def miller_rabin(n, k):
    # we always assume that n >= 2
    if n <= 3:
        return True
    if n == 4:
        return False

    d = n - 1
    while d % 2 == 0:
        d //= 2
    
    for _ in range(0, k):
        if test(d, n) == False:
            return False
    return True