/**
 * String to Integer (atoi)  
 * Myyura
 */

int isNumber(char c) {
    return c >= '0' && c <= '9';
}

int myAtoi(char* str) {
    long int result = 0;
    int sign = 1;
    int numberFlag = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && !numberFlag) {
            // just focus on the spaces at the begining
            continue;
        } else if (str[i] == '-' && isNumber(str[i + 1]) && !numberFlag) {
            sign = -1;
        } else if (str[i] == '+' && isNumber(str[i + 1]) && !numberFlag) {
            sign = 1;
        } else if (isNumber(str[i])) {
            numberFlag = 1;
            result *= 10;
            result += str[i] - '0';

            if (result > INT_MAX) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
        } else {
            break;
        }
    }

    return result * sign;
}