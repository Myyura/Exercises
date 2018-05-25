/**
 * Longest Substring Without Repeating Characters  
 * Myyura
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int lengthOfLongestSubstring(char* s) {
    int charInString[256];
    for (int i = 0; i < 256; i++) {
        charInString[i] = -1;
    }

    int result = 0, start = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (charInString[s[i]] > start) {
            start = charInString[s[i]];
        }
        charInString[s[i]] = i;
        result = max(result, i - start);
    }

    return result;
}