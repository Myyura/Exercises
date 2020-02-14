/**
 * Myyura
 */

/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
 *
 * https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/
 *
 * algorithms
 * Medium (84.15%)
 * Likes:    141
 * Dislikes: 6
 * Total Accepted:    10.1K
 * Total Submissions: 12.1K
 * Testcase Example:  '[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]'
 *
 * Given a binary tree, return the sum of values of nodes with even-valued
 * grandparent.  (A grandparent of a node is the parent of its parent, if it
 * exists.)
 * 
 * If there are no nodes with an even-valued grandparent, return 0.
 * 
 * Example 1:
 * Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * Output: 18
 * Explanation: The red nodes are the nodes with even-value grandparent while
 * the blue nodes are the even-value grandparents.
 * 
 * Constraints:
 * The number of nodes in the tree is between 1 and 10^4.
 * The value of nodes is between 1 and 100.
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
    struct DoubleTreeNode {
        int val;
        DoubleTreeNode *left, *right, *parent;
        DoubleTreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
    };

    DoubleTreeNode* construct_double_tree(TreeNode* current, DoubleTreeNode* parent) {
        if (current == NULL) { return NULL; }

        DoubleTreeNode *n = new DoubleTreeNode(current->val);
        n->parent = parent;
        n->left = construct_double_tree(current->left, n);
        n->right = construct_double_tree(current->right, n);
        return n;
    }

    int sum_even_grandparent(DoubleTreeNode* root) {
        if (root == NULL) { return 0; }

        int even_sum = 0;
        even_sum += sum_even_grandparent(root->left);
        even_sum += sum_even_grandparent(root->right);
        if (root->parent && root->parent->parent) {
            if (root->parent->parent->val % 2 == 0) {
                even_sum += root->val;
            }
        }

        return even_sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        DoubleTreeNode *helper_tree = construct_double_tree(root, NULL);
        return sum_even_grandparent(helper_tree);
    }
};

