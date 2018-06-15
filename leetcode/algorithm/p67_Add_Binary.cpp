/**
 * Add Binary
 * Myyura
 */

/**
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 */

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;
        int i, j, carry = 0;
        for (i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int sum = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + carry;
            carry = sum / 2;
            sum = sum % 2;
            result += sum == 0 ? "0" : "1";
        }
        
        if (carry == 1) { result += "1"; }
        std::reverse(result.begin(), result.end());
        return result;
    }
};