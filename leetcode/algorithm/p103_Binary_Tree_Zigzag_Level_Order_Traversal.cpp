/**
 * Binary Tree Zigzag Level Order Traversal
 * Myyura
 */

/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' 
 * values. (ie, from left to right, then right to left for the right_to_left level and 
 * alternate between).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (root == NULL) { return result; }
        
        std::deque<TreeNode*> left_to_right, right_to_left;
        int flag = 0;
        for (left_to_right.push_back(root); !left_to_right.empty() || !right_to_left.empty();) {
            std::vector<int> level;
            if (flag == 0) {
                for (; !left_to_right.empty();) {
                    TreeNode* temp = left_to_right.front();
                    level.push_back(temp->val);
                    left_to_right.pop_front();
                    if (temp->left) { right_to_left.push_back(temp->left); }
                    if (temp->right) { right_to_left.push_back(temp->right); }
                }
                flag = 1;
            } else {
                for (; !right_to_left.empty();) {
                    TreeNode* temp = right_to_left.back();
                    level.push_back(temp->val);
                    right_to_left.pop_back();
                    if (temp->right) { left_to_right.push_front(temp->right); }
                    if (temp->left) { left_to_right.push_front(temp->left); }
                }
                flag = 0;
            }
            result.push_back(level);
        }
        
        return result;
    }
};