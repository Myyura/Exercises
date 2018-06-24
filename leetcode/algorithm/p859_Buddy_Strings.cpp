/**
 * Buddy Strings
 * Myyura
 */

/**
 * Weekly contest 90
 * Given two strings A and B of lowercase letters, return true if and only if we 
 * can swap two letters in A so that the result equals B.
 * 
 * Example 1:
 * Input: A = "ab", B = "ba"
 * Output: true
 * 
 * Example 2:
 * Input: A = "ab", B = "ab"
 * Output: false
 * 
 * Example 3:
 * Input: A = "aa", B = "aa"
 * Output: true
 * 
 * Example 4:
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * 
 * Example 5:
 * Input: A = "", B = "aa"
 * Output: false
 */

class Solution {
public:
    bool buddyStrings(std::string A, std::string B) {
        if (A == "" || B == "") { return false; }
        if (A.size() != B.size()) { return false; }
        std::vector<int> charCount(26, 0);
        int diffCount = 0, index[4];
        bool isEqual = true;;
        for (int i = 0, j = 0, k = 0; i < A.size(); i++, j++) {
            charCount[(int)(A[i] - 'a')]++;
            if (A[i] != B[j]) { 
                if (++diffCount > 2) { return false; }  
                isEqual = false;
                index[k++] = i, index[k++] = j;
            }
        }
        // Note that "abcabc" and "abcabc" are also resulting equal.
        for (int i = 0; isEqual && i < 26; i++) {
            if (charCount[i] >= 2) {
                return true;
            }
        } 
        return diffCount == 2 && A[index[0]] == B[index[3]] && A[index[2]] == B[index[1]];
    }
};