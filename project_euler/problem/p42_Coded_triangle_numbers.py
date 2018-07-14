# Coded triangle numbers
# Myyura

# The nth term of the sequence of triangle numbers is given by, 
# tn = ½n(n+1); so the first ten triangle numbers are:

# 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

# By converting each letter in a word to a number corresponding to its 
# alphabetical position and adding these values we form a word value. 
# For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If 
# the word value is a triangle number then we shall call the word a 
# triangle word.

# Using words.txt (right click and 'Save Link/Target As...'), a 16K 
# text file containing nearly two-thousand common English words, how 
# many are triangle words?

def count_triangle_words(in_file):
    words = [w[1:-1] for w in in_file.readline().split(",")]
    triangles = [n * (n + 1) / 2 for n in range(1, 30)]
    count = 0
    for w in words:
        if triangles.count(sum([ord(c) - ord("A") + 1 for c in w])):
            count += 1
    return count

in_file = open("../data/p42_words.txt")
print(count_triangle_words(in_file))
in_file.close()