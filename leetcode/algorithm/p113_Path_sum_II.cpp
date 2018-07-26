/**
 * Path Sum II
 * Myyura
 */

/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's 
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * Given the below binary tree and sum = 22,
 * 
 *       5
 *      / \
 *     4   8
 *    /   / \
 *   11  13  4
 *  /  \    / \
 * 7    2  5   1
 * 
 * Return:
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
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
    void pathSum(TreeNode* root,
                 int sum,
                 std::vector<int>& path,
                 std::vector<std::vector<int>>& result) {
        if (sum == root->val) {
            if (root->left == NULL && root->right == NULL) {
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
                return;
            }
        }
        
        path.push_back(root->val);
        if (root->left) { pathSum(root->left, sum - root->val, path, result); }
        if (root->right) { pathSum(root->right, sum - root->val, path, result); }
        path.pop_back();
    }
    
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> result;
        if (!root) { return result; }
        std::vector<int> path;
        pathSum(root, sum, path, result);
        return result;
    }
};