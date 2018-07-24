# Expressing an integer as the sum of triangular numbers
# Myyura

# Gauss famously proved that every positive integer can be expressed as the sum 
# of three triangular numbers (including 0 as the lowest triangular number). In 
# fact most numbers can be expressed as a sum of three triangular numbers in 
# several ways.

# Let G(n) be the number of ways of expressing n as the sum of three triangular 
# numbers, regarding different arrangements of the terms of the sum as distinct.

# For example, G(9)=7, as 9 can be expressed as: 3+3+3, 0+3+6, 0+6+3, 3+0+6, 
# 3+6+0, 6+0+3, 6+3+0.

# You are given G(1000)=78 and G(10^6)=2106.
# Find G(17526×10^9).

# Since the program never stops, I write this algorithm in C++, which finally
# gave the result after running 5000 seconds.

import math

def eratosthenes_sieve(n):
    is_prime = [True for _ in range(n + 1)]
    for p in range(2, int(n ** 0.5) + 1):
        if is_prime[p]:
            for i in range(p * 2, n + 1, p):
                is_prime[i] = False
    return [p for p in range(2, n + 1) if is_prime[p] == True]

def two_squares(n, primes):
    if n <= 1:
        return 0
    
    while n % 2 == 0:
        n //= 2
    
    if n % 4 == 3:
        return 0
    
    result = 1
    for p in primes:
        if p * p > n:
            break
        
        count = 0
        while n % p == 0:
            count += 1
            n //= p
        if p % 4 == 3 and count % 2 == 1:
            return 0
        if p % 4 == 1:
            result *= count + 1
    
    if n > 1:
        result *= 2
    return result

# There is formula for the case of two squares
def three_squares(n):
    primes = eratosthenes_sieve(int(n ** 0.5) + 1)
    return sum(two_squares(n - k * k, primes) for k in range(int(n ** 0.5) + 1))

def three_triangulars(n):
    return three_squares(8 * n + 3)

print(three_triangulars(17526000000000))