/**
 * Binary Tree Postorder Traversal
 * Myyura
 */

/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * 
 * Output: [3,2,1]
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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode *> st;
        std::vector<int> result;
        if (root == NULL) { return result; }
        
        st.push(root);
        for (; !st.empty();) {
            TreeNode *current = st.top();
            if (current->left) { 
                st.push(current->left);
                current->left = NULL;
                continue;
            }
            
            if (current->right) {
                st.push(current->right);
                current->right = NULL;
                continue;
            }
            
            result.push_back(current->val);
            st.pop();
        }
        
        return result;
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode *> st;
        std::vector<int> result;
        if (root == NULL) { return result; }
        
        st.push(root);
        for (; !st.empty();) {
            TreeNode *current = st.top();
            result.insert(result.begin(), current->val);
            st.pop();

            if (current->left) { st.push(current->left); }
            if (current->right) { st.push(current->right); }
        }
        
        return result;
    }
};