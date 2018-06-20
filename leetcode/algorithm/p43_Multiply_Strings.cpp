/**
 * Multiply Strings
 * Myyura
 */

/**
 * Given two non-negative integers num1 and num2 represented as strings, return 
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * Note:
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 * You must not use any built-in BigInteger library or convert the inputs to 
 * integer directly.
 */

class Solution {
public:
    std::string add(std::string num1, std::string num2) {
        if (num1.empty() || num2.empty()) { return ""; }
        std::string result;
        int carry = 0;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int c = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            result += char(c + '0');
        }
        if (carry > 0) { result += "1"; }
        std::reverse(result.begin(), result.end());
        return result;
    }

    std::string multiply(std::string num1, std::string num2) {
        if (num1.empty() || num2.empty()) { return ""; }
        if (num1 == "0" || num2 == "0") { return "0"; }
        std::string result = "0";
        for (int i = num1.size() - 1, tenth = 0; i >= 0; i--, tenth++) {
            std::string ith = "";
            int n1 = num1[i] - '0', carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int c = (n1 * n2 + carry) % 10;
                carry = (n1 * n2 + carry) / 10;
                ith += char(c + '0');
            }
            if (carry > 0) {
                std::string cs = std::to_string(carry);
                std::reverse(cs.begin(), cs.end());
                ith += cs;
            }
            std::reverse(ith.begin(), ith.end());
            for (int j = 0; j < tenth; j++) { ith += "0"; }
            result = add(result, ith);
        }

        return result;
    }
};