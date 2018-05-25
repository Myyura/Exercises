/**
 * ZigZag Conversion      
 * Myyura
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