/**
 * Leaf-Similar Trees
 * Myyura
 */

/**
 * Consider all the leaves of a binary tree.  From left to right order, the 
 * values of those leaves form a leaf value sequence.
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 
 * 8).
 * 
 * Two binary trees are considered leaf-similar if their leaf value sequence is 
 * the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and root2 
 * are leaf-similar.
 * 
 * Note:
 * Both of the given trees will have between 1 and 100 nodes.
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
    void leaves(TreeNode* root, std::vector<int>& l) {
        if (root->left) { leaves(root->left, l); }
        if (root->right) { leaves(root->right, l); }
        if (root->left == NULL && root->right == NULL) { l.push_back(root->val); }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> l1, l2;
        if (root1) { leaves(root1, l1); }
        if (root2) { leaves(root2, l2); }
        if (l1.size() != l2.size()) { return false; }
        for (int i = 0; i < l1.size(); i++) {
            if (l1[i] != l2[i]) { return false; }
        }
        return true;
    }
};