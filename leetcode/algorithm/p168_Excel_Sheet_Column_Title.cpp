/**
 * Excel Sheet Column Title
 * Myyura
 */

/**
 * Given a positive integer, return its corresponding column title as appear in 
 * an Excel sheet.
 *
 * For example:
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 *     ...
 * 
 * Example 1:
 * Input: 1
 * Output: "A"
 * 
 * Example 2:
 * Input: 28
 * Output: "AB"
 * 
 * Example 3:
 * Input: 701
 * Output: "ZY"
 */

class Solution {
public:
    std::string convertToTitle(int n) {
        std::string result = "";
        for (; n > 0; n = (n - 1) / 26) {
            result += (n - 1) % 26 + 'A';
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};