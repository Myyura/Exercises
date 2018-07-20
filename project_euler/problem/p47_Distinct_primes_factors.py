# Distinct primes factors
# Myyura

# The first two consecutive numbers to have two distinct prime factors are:

# 14 = 2 × 7
# 15 = 3 × 5

# The first three consecutive numbers to have three distinct prime factors 
# are:

# 644 = 2² × 7 × 23
# 645 = 3 × 5 × 43
# 646 = 2 × 17 × 19.

# Find the first four consecutive integers to have four distinct prime 
# factors each. What is the first of these numbers?

def generate_primes(ub):
    primes = set()
    for n in range(2, ub):
        if all(n % p for p in primes):
            primes.add(n)

    primes = [p for p in primes]
    primes = sorted(primes)
    return primes

def prime_factors(lb, ub):
    primes = generate_primes(ub // 2)
    num_factors = {}
    for i in range(lb, ub):
        current = i
        factors = set()
        for j in primes:
            while current % j == 0 and current != 0:
                factors.add(j)
                current //= j
        print(factors)
        num_factors[i] = factors
    return num_factors

def distinct_four_prime_factors():
    num_factors = prime_factors(2, 200000)
    for i in range(2, 200000):
        if len(num_factors[i]) == len(num_factors[i + 1]) == len(num_factors[i + 2]) == len(num_factors[i + 3]) == 4:
            return i
    return -1
            
print(distinct_four_prime_factors())