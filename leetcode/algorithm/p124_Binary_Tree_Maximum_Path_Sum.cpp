/**
 * Binary Tree Maximum Path Sum
 * Myyura
 */

/**
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some starting 
 * node to any node in the tree along the parent-child connections. The path must 
 * contain at least one node and does not need to go through the root.
 * 
 * Example 1:
 * Input: [1,2,3]
 * 
 *        1
 *       / \
 *      2   3
 * 
 * Output: 6
 * 
 * Example 2:
 * Input: [-10,9,20,null,null,15,7]
 * 
 *    -10
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * Output: 42
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
    int max4(int a, int b, int c, int d) { return std::max(std::max(a, b), std::max(c, d)); }
    int max3(int a, int b, int c) { return std::max(std::max(a, b), c); }
    
    /**
     * The basic idea is, when we at a node, say p, we consider the maximum path
     * sum that is made up of its descendants.
     *  1. it is made up of p's left child
     *  2. it is made up of p's right child
     *  3. it is made up of p's left child plus p
     *  4. it is made up of p's right child plus p
     *  5. it is made up of p, p's left child and p's right child
     * 
     * Hence we need record the path sum that uses the left (right) child node
     * of p (for cases 3, 4 and 5).
     * 
     * Notice that the value of a node is possibly nagetive, the trick that are 
     * used in the DP algorithm of Subset sum problem is used here, i.e. when 
     * the path that uses the left (right) child node of p has a nagetive sum,
     * we just ignore it.
     */
    int helper(TreeNode* root, int& maxPath) {
        if (root == NULL) { return 0; }
        
        int left = 0, right = 0;
        if (root->left) { left = helper(root->left, maxPath); }
        if (root->right) { right = helper(root->right, maxPath); }
        
        if (left <= 0 && right <= 0) {
            maxPath = std::max(root->val, maxPath);
        } else {
            // the 5 cases
            int leftRight = std::max(left, right);
            maxPath = max4(leftRight, leftRight + root->val, left + right + root->val, maxPath);
        }
        
        return max3(left + root->val, right + root->val, root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxPath = -999999;
        helper(root, maxPath);
        return maxPath;
    }
};