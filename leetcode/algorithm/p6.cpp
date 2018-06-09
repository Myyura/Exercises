/**
 * ZigZag Conversion      
 * Myyura
 */

/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
 * of rows like this: (you may want to display this pattern in a fixed font for 
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number 
 * of rows:
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */

class Solution {
public:
    // Very slow.
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int numColum = (s.size() / (2 * numRows - 2) + 1) * (numRows - 1);
        char zigzag[numRows][numColum];
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColum; j++) {
                zigzag[i][j] = '*';
            }
        }

        for (int i = 0, j = 0, k = 0; k < s.size(); k++) {
            zigzag[i][j] = s.at(k);
            if (j % (numRows - 1) == 0) {
                if (++i == numRows) {
                    i -= 2;
                    j++;
                }
            } else {
                i--, j++;
            }
        }

        std::string result = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColum; j++) {
                if (zigzag[i][j] != '*') {
                    result.push_back(zigzag[i][j]);
                }
            }
        }

        return result;
    }
};