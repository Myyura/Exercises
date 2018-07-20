def eratosthenes_sieve(n):
    is_prime = [True for _ in range(n + 1)]
    for p in range(2, int(n ** 0.5) + 1):
        if is_prime[p]:
            for i in range(p * 2, n + 1, p):
                is_prime[i] = False
    return [p for p in range(2, n + 1) if is_prime[p] == True]

def eratosthenes_sieve_modified(n):
    min_prime_factor = [0 for _ in range(n + 1)]
    primes = []
    for p in range(2, n + 1):
        if min_prime_factor[p] == 0:
            min_prime_factor[p] = p
            primes.append(p)
        for i in range(len(primes)):
            if primes[i] > min_prime_factor[p] or p * primes[i] > n:
                break
            min_prime_factor[p * primes[i]] = primes[i]
    return primes