/**
 * Pow(x, n)
 * Myyura
 */

/**
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * Example 2:
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * Example 3:
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * Note:
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 */

class Solution {
public:
    double myPow(double x, unsigned int n) {
        if (n == 0) { return 1.0; }
        if (n == 1) { return x; }
        if (n % 2 != 0) {
            return myPow(x, n / 2) * myPow(x, n / 2) * x;
        } else {
            return myPow(x, n / 2) * myPow(x, n / 2);
        }
    }
    
    double myPow(double x, int n) {
        unsigned int abs_n = n < 0 ? -n : n;
        if (n >= 0) { return myPow(x, abs_n); }
        return 1 / myPow(x, abs_n);
    }
};