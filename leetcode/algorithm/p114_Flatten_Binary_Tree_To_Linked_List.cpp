/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (46.02%)
 * Likes:    2145
 * Dislikes: 272
 * Total Accepted:    298.8K
 * Total Submissions: 645.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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

/* Each node's right child points to the next node of a pre-order traversal. */
class Solution {
public:
    void get_preorder(TreeNode* root, std::vector<TreeNode*>& pre) {
        if (root == NULL) { return; }

        pre.push_back(root);
        get_preorder(root->left, pre);
        get_preorder(root->right, pre);
        root->left = root->right = NULL;
    }

    void flatten(TreeNode* root) {
        if (root == NULL) { return; }

        std::vector<TreeNode*> pre;
        get_preorder(root, pre);
        
        TreeNode* current = root;
        for (int i = 1; i < pre.size(); i++) {
            current->right = pre[i];
            current = current->right;
        };
    }
};
