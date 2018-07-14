# Pandigital prime
# Myyura

# We shall say that an n-digit number is pandigital if it makes use of all the 
# digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is 
# also prime.

# What is the largest n-digit pandigital prime that exists?

import math

def is_prime(n):
    if n <= 3:
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    else:
        for i in range(5, int(math.sqrt(n)) + 1, 6):
            if n % i == 0 or n % (i + 2) == 0:
                return False
    return True

def next_permutation(s):
    s_copy = list(s)
    k = -1
    for i in range(len(s_copy) - 1):
        if s_copy[i] < s_copy[i + 1]:
            k = i

    if k == -1:
        return s_copy[::-1]
    
    j = -1
    for i in range(k + 1, len(s_copy)):
        if s_copy[i] > s_copy[k]:
            j = i

    s_copy[k], s_copy[j] = s_copy[j], s_copy[k]
    return s_copy[0:k + 1] + s_copy[len(s_copy) - 1:k:-1]

def max_pandigital_prime():
    max_one = -1
    # 1 + ... + 9 = 45, 45 % 3 == 0
    # 1 + ... + 8 = 36, 36 % 3 == 0
    # Hence nine and eight numbers can not be done
    for i in range(7, 0, -1):
        first = list("123456789"[:i])
        if is_prime(int("".join(first))):
            max_one = int("".join(first))
        
        current = next_permutation(first)
        while current != first:
            n = int("".join(current))
            if is_prime(n):
                max_one = max(max_one, n)
            current = next_permutation(current)
        
        if max_one != -1:
            break
    
    return max_one

print(max_pandigital_prime())