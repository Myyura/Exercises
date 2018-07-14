/**
 * Restore IP Addresses
 * Myyura
 */

/**
 * Given a string containing only digits, restore it by returning all possible 
 * valid IP address combinations.
 * 
 * Example:
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 */

class Solution {
public:
    void restoreIpAddresses(std::string& s, 
                            int i, 
                            int count, 
                            std::string& result,
                            std::vector<std::string>& results) {
        if (count == 4) {
            if (i == s.size()) {
                // We have an extra '.' in the end of result
                result.pop_back();
                results.push_back(result);
            }
            return;
        }
        
        for (int j = 1; j <= 3; j++) {
            if (i + j > s.size()) { return; }
            int part = std::stoi(s.substr(i, j));
            // Note that partition like "010 01 00" are not allowed
            if (s[i] == '0' && j > 1) { continue; }
            if (part <= 255) {
                std::string newResult = result + std::to_string(part) + ".";
                restoreIpAddresses(s, i + j, count + 1, newResult, results);
            }
        }
    }
    
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> results;
        std::string result = "";
        restoreIpAddresses(s, 0, 0, result, results);
        return results;
    }
};