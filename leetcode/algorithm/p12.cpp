/**
 * Integer to Roman       
 * Myyura
 */

class Solution {
public:
	std::string intToRoman(int num) {
		const std::vector<std::string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
 		const std::vector<int> value = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
		std::string result;

		for (int i = roman.size() - 1; i >= 0; i--) {
			while (num >= value.at(i))
			{
				result += roman.at(i);
				num -= value.at(i);
			}
		}

		return result;
	}
};