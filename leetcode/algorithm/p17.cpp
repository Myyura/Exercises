/**
 * Letter Combinations of a Phone Number
 * Myyura
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