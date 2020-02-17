/**
 * Myyura
 */

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (42.43%)
 * Likes:    1756
 * Dislikes: 146
 * Total Accepted:    397.8K
 * Total Submissions: 936.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 * 
 * Example 1:
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * Return true.
 * 
 * Example 2:
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * Return false.
 */

/**
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
    int tree_height(TreeNode* root) {
        if (root == NULL) { return 0; }
        int left_height = tree_height(root->left) + 1;
        int right_height = tree_height(root->right) + 1;
        return std::max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) { return true; }

        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        return std::abs(left_height - right_height) <= 1 && 
               isBalanced(root->left) && isBalanced(root->right);
    }
};

