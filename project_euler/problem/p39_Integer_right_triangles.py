# Integer right triangles
# Myyura

# If p is the perimeter of a right angle triangle with integral length sides, 
# {a,b,c}, there are exactly three solutions for p = 120.
# {20,48,52}, {24,45,51}, {30,40,50}
# For which value of p ≤ 1000, is the number of solutions maximised?

# Basic idea:
# Solve the equation a^2 + b^2 = (p - a - b)^2, we have
#                   b = p(p - 2a) / 2(p - a)

def integer_right_triangles(ub):
    max_count = -1
    for p in range(3, ub + 1):
        count = 0
        for a in range(1, p // 3):
            if p * (p - 2 * a) % (2 * (p - a)) == 0:
                count += 1
        
        if count > max_count:
            max_count = count
            max_p = p
    
    return max_p

print(integer_right_triangles(1000))