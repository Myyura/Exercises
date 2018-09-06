/**
 * Increasing Order Search Tree
 * Myyura
 */

/**
 * Given a tree, rearrange the tree in in-order so that the leftmost node in the 
 * tree is now the root of the tree, and every node has no left child and only 1 
 * right child.
 * 
 * Example 1:
 * Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
 *        5
 *       / \
 *     3    6
 *    / \    \
 *   2   4    8
 *  /        / \ 
 * 1        7   9
 * 
 * Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 *  1
 *   \
 *    2
 *     \
 *      3
 *       \
 *        4
 *         \
 *          5
 *           \
 *            6
 *             \
 *              7
 *               \
 *                8
 *                 \
 *                  9  
 * 
 * Note:
 * The number of nodes in the given tree will be between 1 and 100.
 * Each node will have a unique integer value from 0 to 1000.
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
private:
    TreeNode *_prev = NULL, *_head = NULL;
public:
    // Create a new tree
    void getValuesInOrder(TreeNode *root, std::vector<int>& valuesInOrder) {
        if (root == NULL) { return; }
        getValuesInOrder(root->left, valuesInOrder);
        valuesInOrder.push_back(root->val);
        getValuesInOrder(root->right, valuesInOrder);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        std::vector<int> valuesInOrder;
        getValuesInOrder(root, valuesInOrder);
        
        TreeNode *head = NULL, *cur = NULL;
        for (auto& value : valuesInOrder) {
            if (head == NULL) {
                head = new TreeNode(value);
                cur = head;
            } else {
                cur->right = new TreeNode(value);
                cur = cur->right;
            }
        }
        
        return head;
    }
    
    // Rearrange the order of original tree
    void helper(TreeNode* root) {
        if (root == NULL) { return; }
        helper(root->left);
        if (_prev != NULL) {
            root->left = NULL;
            _prev->right = root;
        }
        if (_head == NULL) { _head = root; }
        _prev = root;
        helper(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
        return _head;
    }
};