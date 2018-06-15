/**
 * Substring with Concatenation of All Words
 * Myyura
 */

/**
 * You are given a string, s, and a list of words, words, that are all of the 
 * same length. Find all starting indices of substring(s) in s that is a 
 * concatenation of each word in words exactly once and without any intervening 
 * characters.
 * 
 * Example 1:
 * Input:
 *   s = "barfoothefoobarman",
 *   words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" 
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * Example 2:
 * Input:
 *   s = "wordgoodstudentgoodword",
 *   words = ["word","student"]
 * Output: []
 */
class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (words.size() == 0 || s.size() == 0) { return result; }

        // Since I found that a word can appear more than once in the vector words
        std::map<std::string, int> wordCount;
        for (int i = 0; i < words.size(); i++) {
            if (wordCount.find(words[i]) == wordCount.end()) {
                wordCount[words[i]] = 1;
            } else {
                wordCount[words[i]]++;
            }
        }

        /**
         * Think about the following instance:
         * "lingmindraboofooowingdingbarrwingmonkeypoundcake"
         * ["fooo","barr","wing","ding","wing"]
         * 
         * Hence not only should we check 0, wordSize, 2 * wordSise ..., but also
         * 1, wordSize + 1, ...
         * 2, wordSize + 2, ...
         * ...
         * wordSize - 1, 2 * wordSize - 1, ...
         * should to be checked.
         */
        int wordSize = words[0].size();
        for (int w = 0; w < wordSize; w++) {
            std::map<std::string, int> intervalWordCount;
            int count = 0;
            /**
             * We maintain a interval [i, ..., j] s.t. the substring s(i, j)
             * is a concatenation of words in vector words.
             */
            for (int i = w, j = i; j <= (int)s.size() - wordSize; j += wordSize) {
                std::string curWord = s.substr(j, wordSize);
                // Count the number of each word in s(i, j)
                if (wordCount.find(curWord) != wordCount.end()) {
                    if (intervalWordCount.find(curWord) == intervalWordCount.end()) {
                        intervalWordCount[curWord] = 1;
                    } else {
                        intervalWordCount[curWord]++;
                    }

                    /**
                     * Note that a word (i.e. curWord here) can appear in s(i, j) 
                     * only wordCount[curWord] times.
                     */
                    if (intervalWordCount[curWord] <= wordCount[curWord]) { 
                        count++;
                    } else {
                        // Find the fisrt time that curWord appeared in s(i, j)
                        for (int k = i; ; k += wordSize) {
                            std::string temp = s.substr(k, wordSize);
                            intervalWordCount[temp]--;
                            if (temp == curWord) {
                                i = k + wordSize;
                                break;
                            }
                            count--;
                        }
                    }
                } else {
                    /**
                     * If curWord is not a word in vector words, then every string 
                     * that contains a substring of s(i, j + wordSize) can never be 
                     * an answer we want.
                     */
                    i = j + wordSize;
                    count = 0;
                    intervalWordCount.clear();
                }

                if (count == words.size()) { result.push_back(i); }
            }
        }

        return result;
    }
};