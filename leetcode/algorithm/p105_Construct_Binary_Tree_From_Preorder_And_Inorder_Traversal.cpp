/**
 * Myyura
 */

/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (45.30%)
 * Likes:    2564
 * Dislikes: 75
 * Total Accepted:    299.7K
 * Total Submissions: 658.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
        std::vector<int>& preorder,
        int& pre_index,
        std::vector<int>& inorder,
        int in_start,
        int in_end) {
        // cout << in_start << " " << in_end << endl;
        if (in_start > in_end) { return NULL; }

        TreeNode* node = new TreeNode(preorder[pre_index++]);

        if (in_start == in_end) { return node; }

        int in_index;
        for (in_index = in_start; in_index <= in_end; in_index++) {
            if (node->val == inorder[in_index]) {
                break;
            }
        }

        node->left = buildTree(preorder, pre_index, inorder, in_start, in_index - 1);
        node->right = buildTree(preorder, pre_index, inorder, in_index + 1, in_end);
        return node;
    } 

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int pre_index = 0;
        return buildTree(preorder, pre_index, inorder, 0, inorder.size() - 1);
    }
};

