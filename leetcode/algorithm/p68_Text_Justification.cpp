/**
 * Text Justification
 * Myyura
 */

/**
 * Given an array of words and a width maxWidth, format the text such that each 
 * line has exactly maxWidth characters and is fully (left and right) justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words 
 * as you can in each line. Pad extra spaces ' ' when necessary so that each line 
 * has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If 
 * the number of spaces on a line do not divide evenly between words, the empty 
 * slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is 
 * inserted between words.
 * 
 * Note:
 * A word is defined as a character sequence consisting of non-space characters 
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
 * The input array words contains at least one word.
 * 
 * Example 1:
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * 
 * Example 2:
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 *   "What   must   be",
 *   "acknowledgment  ",
 *   "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall     be",
 * because the last line must be left-justified instead of fully-justified.
 * Note that the second line is also left-justified becase it contains only one 
 * word.
 * 
 * Example 3:
 * Input:
 * words = ["Science","is","what","we","understand","well","enough","to",
 * "explain", "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 *   "Science  is  what we",
 *   "understand      well",
 *   "enough to explain to",
 *   "a  computer.  Art is",
 *   "everything  else  we",
 *   "do                  "
 * ]
 */

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        std::vector<std::string> currentWords;
        int currentWordsLength = 0, currentWordsCount = 0;
        for (auto& w : words) {
            if (currentWordsLength + w.size() + currentWordsCount > maxWidth) {
                int spaces = maxWidth - currentWordsLength;
                std::string newLine = "";
                if (currentWordsCount == 1) {
                    newLine += currentWords[0];
                    for (int i = 0; i < spaces; i++) { newLine += " "; }
                    currentWordsCount--;
                } else {
                    int base = spaces / (currentWordsCount - 1);
                    int left = spaces % (currentWordsCount - 1);
                    for (auto& cw : currentWords) {
                        newLine += cw;
                        if (--currentWordsCount == 0) { continue; }
                        for (int i = 0; i < base; i++) { newLine += " "; }
                        newLine += left-- > 0 ? " " : "";
                    }
                }
                result.push_back(newLine);
                currentWords.clear();
                currentWordsLength = 0;
            }
            
            currentWords.push_back(w);
            currentWordsCount++;
            currentWordsLength += w.size();
        }
        
        std::string lastLine = "";
        for (auto& cw : currentWords) { lastLine += cw + " "; }
        if (lastLine.size() <= maxWidth) {
            for (int i = lastLine.size(); i < maxWidth; i++) { lastLine += " "; }
        } else { lastLine.pop_back(); }
        result.push_back(lastLine);
        
        return result;
    }
};