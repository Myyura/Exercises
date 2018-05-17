int romanToInt(char* s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'V') {
                result += 4;
                i++;
            } else if (s[i + 1] == 'X') {
                result += 9;
                i++;
            } else {
                result += 1;
            }
        }

        if (s[i] == 'X') {
            if (s[i + 1] == 'L') {
                result += 40;
                i++;
            } else if (s[i + 1] == 'C') {
                result += 90;
                i++;
            } else {
                result += 10;
            }
        }

        if (s[i] == 'C') {
            if (s[i + 1] == 'D') {
                result += 400;
                i++;
            } else if (s[i + 1] == 'M') {
                result += 900;
                i++;
            } else {
                result += 100;
            }
        }

        switch(s[i]) {
            case 'V': result += 5;
            case 'L': result += 50;
            case 'D': result += 500;
            case 'M': result += 1000;
        };
    }

    return result;
}