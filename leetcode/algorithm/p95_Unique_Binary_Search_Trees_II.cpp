/**
 * Unique Binary Search Trees II
 * Myyura
 */

/**
 * Given an integer n, generate all structurally unique BST's (binary search 
 * trees) that store values 1 ... n.
 * 
 * Example:
 * Input: 3
 * Output:
 * [
 *   [1,null,3,2],
 *   [3,2,null,1],
 *   [3,1,null,null,2],
 *   [2,1,3],
 *   [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
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
    TreeNode* cloneTree(TreeNode* root) {
        if (root == NULL) { return NULL; }
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = cloneTree(root->left);
        newRoot->right = cloneTree(root->right);
        return newRoot;
    }
    
    std::vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode*> result;
        if (n == 0) { return result; }
        
        result.push_back(NULL);
        for (int i = 1; i <= n; i++) {
            std::vector<TreeNode*> tempResult;
            /**
             * when we insert a new node into a tree, there are two cases: 
             * whether new node is the root of the new tree or not
             */
            for (auto oldTree : result) {
                TreeNode* newNode1 = new TreeNode(i);
                /**
                 * the case new node is the root, note that all value in old 
                 * tree are less than i.
                 */
                newNode1->left = cloneTree(oldTree);
                tempResult.push_back(newNode1);
                if (oldTree == NULL) { continue; }

                /**
                 * the case new node is not the root, then we insert the new 
                 * node in the old tree, note that all value in old tree are 
                 * less than i, hence we only need check the right subtree
                 */
                TreeNode* subRoot = oldTree;
                for (; subRoot->right != NULL; subRoot = subRoot->right) {
                    TreeNode* newNode2 = new TreeNode(i);
                    TreeNode* temp = subRoot->right;
                    subRoot->right = newNode2;
                    newNode2->left = temp;
                    tempResult.push_back(cloneTree(oldTree));
                    subRoot->right = temp;
                    delete newNode2;
                }
                TreeNode* newNode2 = new TreeNode(i);
                subRoot->right = newNode2;
                tempResult.push_back(cloneTree(oldTree));
                subRoot->right = NULL;
                delete newNode2;
            }
            result = tempResult;
        }
        
        return result;
    }
};