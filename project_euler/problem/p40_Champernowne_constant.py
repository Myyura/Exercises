# Champernowne's constant
# Myyura

# An irrational decimal fraction is created by concatenating the positive 
# integers:

# 0.123456789101112131415161718192021...

# It can be seen that the 12th digit of the fractional part is 1.
# If d_n represents the nth digit of the fractional part, find the value of the 
# following expression.

# d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000

import itertools

def champernowne_constant(ub):
    frac = ""
    d = 1
    result = 1
    for i in itertools.count():
        if d > ub: break
        
        if d <= len(frac):
            result *= int(frac[d - 1])
            d *= 10
        frac += str(i + 1)
    
    return result

print(champernowne_constant(1000000))