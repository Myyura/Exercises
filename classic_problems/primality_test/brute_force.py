def brute_force(n):
    if all(n % p for p in range(2, int(n**0.5) + 1)):
        return True
    return False

def brute_force_6k(n):
    if n <= 3:
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    else:
        for p in range(5, int(n ** 0.5) + 1, 6):
            if n % p == 0 or n % (p + 2) == 0:
                return False
    return True