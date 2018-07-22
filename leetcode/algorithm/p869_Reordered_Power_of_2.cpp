/**
 * Reordered Power of 2
 * Myyura
 */

/**
 * Starting with a positive integer N, we reorder the digits in any order 
 * (including the original order) such that the leading digit is not zero.
 * 
 * Return true if and only if we can do this in a way such that the resulting 
 * number is a power of 2.
 * 
 * Example 1:
 * Input: 1
 * Output: true
 * 
 * Example 2:
 * Input: 10
 * Output: false
 * 
 * Example 3:
 * Input: 16
 * Output: true
 * 
 * Example 4:
 * Input: 24
 * Output: false
 * 
 * Example 5:
 * Input: 46
 * Output: true
 * 
 * Note:
 * 1 <= N <= 10^9
 */

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int length = 0, n = N;
        for (; n != 0; n /= 10, length++) {}
        std::string stringN = std::to_string(N);
        std::sort(stringN.begin(), stringN.end());
        
        std::vector<int> powerOf2(31, 1);
        for (int i = 0, j = 1; i <= 30; i++, j *= 2) { powerOf2[i] = j; }
        
        for (auto& power : powerOf2) {
            std::string stringP = std::to_string(power);
            if (stringP.size() == stringN.size()) {
                std::sort(stringP.begin(), stringP.end());
                if (stringP == stringN) { return true; }
            }
            if (stringP.size() > stringN.size()) { break; }
        }
        
        return false;
    }
};