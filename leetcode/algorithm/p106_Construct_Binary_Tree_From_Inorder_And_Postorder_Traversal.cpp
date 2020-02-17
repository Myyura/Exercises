/**
 * Myyura
 */

/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (42.76%)
 * Likes:    1251
 * Dislikes: 27
 * Total Accepted:    190.3K
 * Total Submissions: 443.1K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(
        std::vector<int>& postorder,
        int& post_index,
        std::vector<int>& inorder,
        int in_start,
        int in_end) {
        // cout << in_start << " " << in_end << endl;
        if (in_start > in_end) { return NULL; }

        TreeNode* node = new TreeNode(postorder[post_index--]);

        if (in_start == in_end) { return node; }

        int in_index;
        for (in_index = in_start; in_index <= in_end; in_index++) {
            if (node->val == inorder[in_index]) {
                break;
            }
        }

        node->right = buildTree(postorder, post_index, inorder, in_index + 1, in_end);
        node->left = buildTree(postorder, post_index, inorder, in_start, in_index - 1);
        return node;
    } 

    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        int post_index = postorder.size() - 1;
        return buildTree(postorder, post_index, inorder, 0, inorder.size() - 1);
    }
};
