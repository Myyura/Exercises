/**
 * Symmetric Tree
 * Myyura
 */

/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric 
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *rightLeftSwap(struct TreeNode *root) {
    if (root == NULL) { return NULL; }
    struct TreeNode *temp = rightLeftSwap(root->right);
    root->right = rightLeftSwap(root->left);
    root->left = temp;
    return root;
}

int isSame(struct TreeNode *t1, struct TreeNode *t2) {
    if (t1 == NULL || t2 == NULL) { return t1 == t2; }
    return t1->val == t2->val && isSame(t1->left, t2->left)
        && isSame(t1->right, t2->right);
}

int isSymmetric(struct TreeNode* root) {
    if (root == NULL) { return true; }
    root->right = rightLeftSwap(root->right);
    return isSame(root->left, root->right);
}