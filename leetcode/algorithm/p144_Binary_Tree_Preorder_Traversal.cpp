/**
 * Binary Tree Preorder Traversal
 * Myyura
 */

/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * 
 * Output: [1,2,3]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode *> st;
        std::vector<int> result;
        if (root == NULL) { return result; }
        
        st.push(root);
        for (; !st.empty();) {
            TreeNode *current = st.top();
            result.push_back(current->val);
            st.pop();
            
            if (current->right) { st.push(current->right); }
            if (current->left) { st.push(current->left); }
        }
        
        return result;
    }
    
};