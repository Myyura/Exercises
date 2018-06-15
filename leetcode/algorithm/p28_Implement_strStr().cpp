/**
 * Implement strStr()
 * Myyura
 */

/**
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if needle 
 * is not part of haystack.
 * 
 * Example 1:
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * Clarification:
 * What should we return when needle is an empty string? This is a great question 
 * to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty 
 * string. This is consistent to C's strstr() and Java's indexOf().
 */

class Solution {
public:
    // Brute-force
    int strStr(std::string haystack, std::string needle) {
        if (needle == "") { return 0; }
        if (haystack == "") { return -1; }
        
        for (int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; i++) {
            bool isFind = true;
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    isFind = false;
                    break;
                }
            }
            
            if (isFind) { return i; }
        }
        
        return -1;
    }
};