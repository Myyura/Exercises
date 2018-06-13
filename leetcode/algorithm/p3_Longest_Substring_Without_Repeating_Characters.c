/**
 * Longest Substring Without Repeating Characters  
 * Myyura
 */

/**
 * Given a string, find the length of the longest substring without repeating 
 * characters.
 * 
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the 
 * answer must be a substring, "pwke" is a subsequence and not a substring.
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