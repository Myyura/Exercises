/**
 * Permutation Sequence
 * Myyura
 */

/**
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the following 
 * sequence for n = 3:
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * 
 * Note:
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * Example 1:
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * Example 2:
 * Input: n = 4, k = 9
 * Output: "2314"
 */

class Solution {
public:
    // see problem 31 for details, which beats only 3% of cpp submissions :).
    void reverse(std::string& s, int k) {
        for (int i = k, j = s.size() - 1; j > i; i++, j--) {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    void nextPermutation(std::string& s) {
        int k = -1;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] < s[i + 1]) { k = i; }
        }

        if (k == -1) {
            reverse(s, 0);
            return;
        }

        int j = -1;
        for (int i = k + 1; i < s.size(); i++) {
            if (s[i] > s[k]) { j = i; }
        }

        int temp = s[k];
        s[k] = s[j];
        s[j] = temp;
        reverse(s, k + 1);
    }
    
    std::string getPermutation(int n, int k) {
        std::string result;
        for (int i = 0; i < n; i++) { result += (char)(i + '1'); }
        for (int i = 1; i < k; i++) {
            nextPermutation(result);
        }
        return result;
    }
};