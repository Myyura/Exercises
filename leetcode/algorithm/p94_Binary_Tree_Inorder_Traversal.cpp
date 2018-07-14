/**
 * Binary Tree Inorder Traversal
 * Myyura
 */

/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * 
 * Output: [1,3,2]
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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode *> st;
        for (TreeNode *current = root; current || !st.empty();) {
            if (current) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                result.push_back(current->val);
                st.pop();
                current = current->right;
            }
        }
        
        return result;
    }
};