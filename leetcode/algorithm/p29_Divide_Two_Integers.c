/**
 * Divide Two Integers
 * Myyura
 */

/**
 * Given two integers dividend and divisor, divide two integers without using 
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers 
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of 
 * this problem, assume that your function returns 231 − 1 when the division 
 * result overflows.
 */

int divide(int dividend, int divisor) {
    int sign = (dividend < 0 && divisor < 0) || (dividend >= 0 && divisor >= 0) ? 1 : -1;
    long int absDividend = labs(dividend), absDivisor = labs(divisor);

    long int i = 1, iDivisor = absDivisor;
    long int quotient = 0;
    for (long int remainder = absDividend; remainder >= absDivisor;) {
        if (remainder - iDivisor <= 0) {
            iDivisor = absDivisor;
            i = 1;
        }

        remainder -= iDivisor;
        quotient += i;
        i += i, iDivisor += iDivisor;
    }

    long int result = quotient * sign;
    if (result > INT_MAX) { return INT_MAX; }
    if (result < INT_MIN) { return INT_MIN; }
    return result;
}