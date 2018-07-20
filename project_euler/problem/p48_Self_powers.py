# Self powers
# Myyura

# The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

# Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

def self_powers(ub):
    sum = 0
    for i in range(1, ub + 1):
        sum += i ** i
    return sum
            
print(self_powers(1000))