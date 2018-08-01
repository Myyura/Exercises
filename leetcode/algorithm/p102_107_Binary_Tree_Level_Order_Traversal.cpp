/**
 * Binary Tree Level Order Traversal
 * Myyura
 */

/**
 * Given a binary tree, return the level order traversal of its nodes' values. 
 * (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
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
    /**
     * A simple BFS, and with reversing the result, we can get the solution for
     * problem 107 - Binary Tree Level Order Traversal II.
     */
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (root == NULL) { return result; }
        
        std::vector<int> level;
        std::queue<TreeNode*> currentLevel;
        currentLevel.push(root);
        for (; !currentLevel.empty();) {
            int currentSize = currentLevel.size();
            for (int i = 0; i < currentSize; i++) {
                TreeNode *temp = currentLevel.front();
                level.push_back(temp->val);
                if (temp->left) { currentLevel.push(temp->left); }
                if (temp->right) { currentLevel.push(temp->right); }
                currentLevel.pop();
            }
            result.push_back(level);
            level.clear();
        }
        
        return result;
    }
};