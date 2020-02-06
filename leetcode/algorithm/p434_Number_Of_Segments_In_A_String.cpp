/**
 * Myyura
 */

/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.44%)
 * Likes:    173
 * Dislikes: 664
 * Total Accepted:    67.7K
 * Total Submissions: 180.7K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * Input: "Hello, my name is John"
 * Output: 5
 */

class Solution {
public:
    int countSegments(std::string s) {
        int i = 0;
        for (; i < s.size() && s[i] == ' '; i++) {}
        if (i == s.size()) { return 0; }
        for (; s.back() == ' '; s.pop_back()) {}

        int segments = 0;
        for (; i < s.size() - 1; i++) {
            if (s[i] == ' ' && s[i + 1] != ' ') { segments++; }
        }
        return segments + 1;
    }
};

