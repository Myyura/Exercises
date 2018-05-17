class Solution {
public:
	string intToRoman(int num) {
		const vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
 		const vector<int> value = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
		string result;

		for (int i = roman.size() - 1; i >= 0; i--) {
			while (num >= value[i])
			{
				result += roman[i];
				num -= value[i];
			}
		}

		return result;
	}
};