/**
 * Myyura
 */

/*
 * @lc app=leetcode id=1104 lang=cpp
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 *
 * https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/
 *
 * algorithms
 * Medium (70.93%)
 * Likes:    215
 * Dislikes: 121
 * Total Accepted:    12.7K
 * Total Submissions: 17.9K
 * Testcase Example:  '14'
 *
 * In an infinite binary tree where every node has two children, the nodes are
 * labelled in row order.
 * 
 * In the odd numbered rows (ie., the first, third, fifth,...), the labelling
 * is left to right, while in the even numbered rows (second, fourth,
 * sixth,...), the labelling is right to left.
 * 
 * Given the label of a node in this tree, return the labels in the path from
 * the root of the tree to the node with that label.
 * 
 * Example 1:
 * Input: label = 14
 * Output: [1,3,4,14]
 * 
 * Example 2:
 * Input: label = 26
 * Output: [1,2,6,10,26]
 * 
 * Constraints:
 * 1 <= label <= 10^6
 */

class Solution {
public:
    std::vector<int> pathInZigZagTree(int label) {
        std::vector<int> path;

        int depth = 1, start = 1, diff = 1, n = 1;
        for (; start + n <= label; n *= 2) {
            depth++, start += n, diff = -diff;
        }

        int pos;
        if (diff > 0) {
            pos = label - start + 1;
        } else {
            pos = n - (label - start);
        }
        for (; depth > 0; depth--) {
            if (diff > 0) {
                path.push_back(start + pos - 1);
            } else {
                path.push_back(start + n - pos);
            }
            n /= 2;
            start = start / 2;
            diff = -diff;
            pos = (pos + 1) / 2;
        }

        std::reverse(path.begin(), path.end());
        return path;
    }
};

