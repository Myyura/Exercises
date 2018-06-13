/**
 * Reverse Nodes in k-Group
 * Myyura
 */

/**
 * The count-and-say sequence is the sequence of integers with the first five 
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a string.
 * 
 * Example 1:
 * Input: 1
 * Output: "1"
 * 
 * Example 2:
 * Input: 4
 * Output: "1211"
 */

class Solution {
public:
    std::string countAndSay(std::string s) {
        std::string say = "";
        int count = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != s[i + 1]) {
                say += std::to_string(++count);
                say += s[i];
                count = 0;
            } else { count++; }
        }

        if (count != 0) {
            say += std::to_string(++count);
        } else {
            say += "1";
        }
        say += s[s.size() - 1];

        return say;
    }

    std::string countAndSay(int n) {
        std::string say = "1";
        for (int count = 1; count < n; count++) {
            say = countAndSay(say);
        }
        return say;
    }
};