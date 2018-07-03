/**
 * Simplify Path
 * Myyura
 */

/**
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, 
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stringstream ss(path);
        std::string token, result;
        std::deque<std::string> dq;
        // I'm wondering why there is no split method for std::string in C++
        for(; std::getline(ss, token, '/');) {
            if (token.empty() || token == ".") { continue; }
            if (token == "..") {
                if (!dq.empty()) { dq.pop_back(); }
                continue;
            }
            dq.push_back(token);
        }
        
        for (auto& it : dq) { result += ('/' + it); }
        if (result.empty()) { return "/"; }
        return result;
    }
};