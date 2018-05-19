/**
 * Reverse Integer
 * Myyura
 */

int reverse(int x) {
    long int result = 0;
    int flag = x > 0 ? 1 : -1;
    x *= flag;
    while (x != 0) {
        result *= 10;
        result += x % 10;
        x /= 10;
    }

    if (result > INT_MAX || result < INT_MIN) {
        return 0;
    }
    
    return result * flag;
}