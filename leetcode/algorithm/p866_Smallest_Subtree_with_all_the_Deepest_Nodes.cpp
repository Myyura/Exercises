/**
 * Smallest Subtree with all the Deepest Nodes
 * Myyura
 */

/**
 * Given a binary tree rooted at root, the depth of each node is the shortest 
 * distance to the root.
 * 
 * A node is deepest if it has the largest depth possible.
 * 
 * Return the node with the largest depth such that it contains all the deepest  * nodes in it's subtree.
 * 
 * Example 1:
 * Input: [3,5,1,6,2,0,8,null,null,7,4]
 * Output: [2,7,4]
 * Explanation:
 * 
 * We return the node with value 2, colored in yellow in the diagram.
 * The nodes colored in blue are the deepest nodes of the tree.
 * The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the
 * given tree.
 * The output "[2, 7, 4]" is a serialization of the subtree rooted at the node 
 * with value 2.
 * Both the input and output have TreeNode type.
 * 
 * Note:
 * The number of nodes in the tree will be between 1 and 500.
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
    TreeNode *subtreeWithAllDeepest(TreeNode *current, std::map<TreeNode*, int>& depths, int depth) {
        if (current->left == NULL && current->right == NULL) {
            depths[current] = depth;
            return current;
        }
		if (current->left == NULL) { 
            return subtreeWithAllDeepest(current->right, depths, depth + 1); 
        }
		if (current->right == NULL) { 
            return subtreeWithAllDeepest(current->left, depths, depth + 1); 
        }
        
		TreeNode *left = subtreeWithAllDeepest(current->left, depths, depth + 1);
		TreeNode *right = subtreeWithAllDeepest(current->right, depths, depth + 1);
		if (depths[left] == depths[right]) {
			depths[current] = depths[left];
			return current;
		}
		return depths[left] > depths[right] ? left : right;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL) { return NULL; }
        std::map<TreeNode*, int> depths;
        return subtreeWithAllDeepest(root, depths, 1);
    }
};