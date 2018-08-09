# Largest exponential
# Myyura

# Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, 
# as any calculator would confirm that 2^11 = 2048 < 3^7 = 2187.

# However, confirming that 632382^518061 > 519432^525806 would be much more 
# difficult, as both numbers contain over three million digits.

# Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file 
# containing one thousand lines with a base/exponent pair on each line, determine 
# which line number has the greatest numerical value.

# NOTE: The first two lines in the file represent the numbers in the example given 
# above.

import math

def largest_exponential():
    input_file = open("../data/p99_base_exp.txt")

    largest_exp = 0
    largest_line_number = -1

    line_number = 0
    for line in input_file:
        line_number += 1
        line = line.split(",")
        base = int(line[0])
        exp = int(line[1])
        value = math.log(base) * exp
        if value > largest_exp:
            largest_exp = value
            largest_line_number = line_number
    
    input_file.close()
    return largest_line_number

print(largest_exponential())