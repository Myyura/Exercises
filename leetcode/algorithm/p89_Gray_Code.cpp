/**
 * Gray Code
 * Myyura
 */

/**
 * The gray code is a binary numeral system where two successive values differ 
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the 
 * code, print the sequence of gray code. A gray code sequence must begin with 0.
 * 
 * Example 1:
 * 
 * Input: 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * Example 2:
 * 
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0. A gray code 
 * sequence of n has size = 2n, which for n = 0 the size is 20 = 1. Therefore, 
 * for n = 0 the gray code sequence is [0].
 */

class Solution {
public:
    // https://en.wikipedia.org/wiki/Gray_code
    int binaryToInteger(std::vector<int> binary) {
        int result = 0, base = 1;
        for (int i = binary.size() - 1; i >= 0; i--) {
            result += base * binary[i];
            base *= 2;
        }
        return result;
    }
    
    std::vector<int> grayCode(int n) {
        if (n == 0) { return std::vector<int> (1, 0); }
        std::vector<int> result, gray(n, 0);
        int upper = std::pow(2, n);
        for (int i = 0; i < upper; i++) {
            result.push_back(binaryToInteger(gray));
            if (i % 2 == 0) { 
                gray[n - 1] = !gray[n - 1]; 
            } else if (i != upper - 1) {
                int first1 = n - 1;
                for (; gray[first1] == 0; first1--) {}
                gray[first1 - 1] = !gray[first1 - 1];
            }
        }
        return result;
    }
};