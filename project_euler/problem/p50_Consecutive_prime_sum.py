# Consecutive prime sum
# Myyura

# The prime 41, can be written as the sum of six consecutive primes:

# 41 = 2 + 3 + 5 + 7 + 11 + 13
# This is the longest sum of consecutive primes that adds to a prime below
#  one-hundred.

# The longest sum of consecutive primes below one-thousand that adds to a prime, 
# contains 21 terms, and is equal to 953.

# Which prime, below one-million, can be written as the sum of the most 
# consecutive primes?

def eratosthenes_sieve(l, r):
    is_prime = [True for _ in range(r + 1)]
    for p in range(2, int(r ** 0.5) + 1):
        if is_prime[p]:
            for i in range(p * 2, r + 1, p):
                is_prime[i] = False
    return [p for p in range(l, r + 1) if is_prime[p] == True]

def consecutive_prime_sum(ub):
    primes = eratosthenes_sieve(2, ub - 1)

    max_sum, max_count = 0, 0
    for i in range(len(primes)):
        cur_sum = 0
        for j in range(i + 1, len(primes)):
            cur_sum += primes[j]
            if cur_sum > ub:
                break
            if cur_sum in primes and j - i > max_count:
                max_count = j - i
                max_sum = cur_sum
    return max_sum

print(consecutive_prime_sum(1000000))