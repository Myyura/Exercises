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

def jacobian_symbol(a, n):
    if a == 0:
        return 0

    result = 1
    if a < 0:
        a = -a
        if n % 4 == 3:
            result = -result
    
    if a == 1:
        return result
    
    while a != 0:
        if a < 0:
            a = -a
            if n % 4 == 3:
                result = -result
        
        while a % 2 == 0:
            a //= 2
            if n % 8 == 3 or n % 8 == 5:
                result = -result
        
        a, n = n, a
        if a % 4 == 3 and n % 4 == 3:
            result = -result
        
        a %= n
        if a > n // 2:
            a -= n

    if n == 1:
        return result
    return 0

def solovay_strassen(n, k):
    if n != 2 and n % 2 == 0:
        return False
    
    for _ in range(0, k):
        a = random.randint(1, n - 1)
        j = (n + jacobian_symbol(a, n)) % n
        r = power(a, (n - 1) // 2, n)

        if not j or r != j:
            return False
    
    return True

for i in range(2, 100):
    if solovay_strassen(i, 5):
        print(i)