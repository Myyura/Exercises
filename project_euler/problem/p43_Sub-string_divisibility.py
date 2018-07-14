# Sub-string divisibility
# Myyura

# The number, 1406357289, is a 0 to 9 pandigital number because it is 
# made up of each of the digits 0 to 9 in some order, but it also has 
# a rather interesting sub-string divisibility property.

# Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

# d2d3d4=406 is divisible by 2
# d3d4d5=063 is divisible by 3
# d4d5d6=635 is divisible by 5
# d5d6d7=357 is divisible by 7
# d6d7d8=572 is divisible by 11
# d7d8d9=728 is divisible by 13
# d8d9d10=289 is divisible by 17
# Find the sum of all 0 to 9 pandigital numbers with this property.

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

def sum_substr_divisibility():
    n = list("1023456789")
    primes = [2, 3, 5, 7, 11, 13, 17]
    sum = 0
    while n != list("0123456789"):
        flag = True
        for i in range(1, 8):
            if int("".join(n[i:i + 3])) % primes[i - 1] != 0:
                flag = False
                break
        if flag:
            sum += int("".join(n))

        n = next_permutation(n)
    
    return sum

print(sum_substr_divisibility())