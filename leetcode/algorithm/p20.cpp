/**
 * Valid Parentheses 
 * Myyura
 */

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 *  Open brackets must be closed by the same type of brackets.
 *  Open brackets must be closed in the correct order.
 *  Note that an empty string is also considered valid.
 */

class Solution {
public:
    bool isMatch(char a, char b) {
        if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}') {
            return true;
        }

        return false;
    }

    bool isValid(std::string s) {
        std::stack<char> st;
        for (auto& it : s) {
            if (it == '{' || it == '[' || it == '(') { st.push(it); }
            if (it == ')' || it == ']' || it == '}') {
                if (st.size() == 0) { return false; }
                char last = st.top();
                st.pop();
                if (!isMatch(last, it)) { return false; }
            }
        }

        if (st.size()) { return false; }

        return true;
    }
};