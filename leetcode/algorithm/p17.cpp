/**
 * Letter Combinations of a Phone Number
 * Myyura
 */

/**
 * Given a string containing digits from 2-9 inclusive, return all possible 
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given 
 * below. Note that 1 does not map to any letters.
 * 
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be 
 * in any order you want.
 */

class Solution {
public:
    std::array <std::string, 10> phoneCharacter = {"", "",
                                                   "abc",
                                                   "def",
                                                   "ghi",
                                                   "jkl",
                                                   "mno",
                                                   "pqrs",
                                                   "tuv",
                                                   "wxyz"};

    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits == "") {
            return result;
        }

        std::vector<int> numbers(digits.size());
        std::vector<int> carry(digits.size());
        std::vector<int> currentPermutation(digits.size());

        for (int i = 0; i < digits.size(); i++) {
            numbers[i] = std::stoi(digits.substr(i, 1));
            carry[i] = phoneCharacter[numbers[i]].size();
            currentPermutation[i] = 0;
        }

        for (; currentPermutation[digits.size() - 1] != carry[digits.size() - 1]; ) {
            std::string s = "";
            for (int i = 0; i < digits.size(); i++) {
                s += phoneCharacter[numbers[i]][currentPermutation[i]];
            }
            currentPermutation[0]++;
            for (int i = 0; i < digits.size() - 1; i++) {
                if (currentPermutation[i] == carry[i]) {
                    currentPermutation[i] = 0;
                    currentPermutation[i + 1]++;
                }
            }
            result.push_back(s);
        }

        return result;
    }
};