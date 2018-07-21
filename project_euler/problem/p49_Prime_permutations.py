# Prime permutations
# Myyura

# The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases 
# by 3330, is unusual in two ways: (i) each of the three terms are prime, and, 
# (ii) each of the 4-digit numbers are permutations of one another.

# There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, 
# exhibiting this property, but there is one other 4-digit increasing sequence.

# What 12-digit number do you form by concatenating the three terms in this 
# sequence?

def eratosthenes_sieve(l, r):
    is_prime = [True for _ in range(r + 1)]
    for p in range(2, int(r ** 0.5) + 1):
        if is_prime[p]:
            for i in range(p * 2, r + 1, p):
                is_prime[i] = False
    return [p for p in range(l, r + 1) if is_prime[p] == True]

def prime_permutations(ub):
    primes = eratosthenes_sieve(1489, ub - 1)

    for i in range(len(primes)):
        for j in range(i + 1, len(primes)):
            prime_k = 2 * primes[j] - primes[i]
            if prime_k < ub and prime_k in primes:
                if set(str(prime_k)) == set(str(primes[i])) == set(str(primes[j])):
                    return str(primes[i]) + str(primes[j]) + str(prime_k)
    return -1

print(prime_permutations(10000))