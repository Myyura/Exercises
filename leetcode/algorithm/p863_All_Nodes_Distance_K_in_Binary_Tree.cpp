/**
 * All Nodes Distance K in Binary Tree
 * Myyura
 */

/**
 * We are given a binary tree (with root node root), a target node, and an 
 * integer value `K`.
 * 
 * Return a list of the values of all nodes that have a distance K from the 
 * target node.  The answer can be returned in any order.
 * 
 * Example 1:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * Output: [7,4,1]
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these objects.
 * 
 * Note:
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
 */

class Solution {
public:
    /**
     * Basic idea: 
     * Observation: The path (i.e. the distance) from a node to its descendants 
     * is easy to find (calculate).
     * 
     * For a node n, if n is a descendant of target, the observation tell us it
     * is easy to calculate the distance(target, n).
     * 
     * Otherwise n must has an ancestor in P. Then the distance from n to target
     * is distance(p, target) + distance(p, n), which are easy to calculate by 
     * the observation.
     * 
     * Hence all we need is a path from root to the target.
     */
    bool find(TreeNode* root, TreeNode* target, std::vector<int>& path) {
        if (root == target) { return true; }
        if (root->left != NULL) {
            path.push_back(1);
            if (find(root->left, target, path)) { return true; }
            path.pop_back();
        }
        if (root->right != NULL) {
            path.push_back(-1);
            if (find(root->right, target, path)) { return true; }
            path.pop_back();
        }
        
        return false;
    }
    
    void distanceK(TreeNode* root, int K, int dist, std::vector<int>& result) {
        if (root == NULL) { return; }
        if (dist == K) { result.push_back(root->val); }
        if (root->left != NULL) { distanceK(root->left, K, dist + 1, result); }
        if (root->right != NULL) { distanceK(root->right, K, dist + 1, result); }
    }
    
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        std::vector<int> pathToTarget, result;
        find(root, target, pathToTarget);
        int dist = pathToTarget.size();
        std::cout << dist << std::endl;
        for (auto& it : pathToTarget) {
            if (K == dist) { result.push_back(root->val); }
            if (it == 1) {
                distanceK(root->right, K, dist + 1, result);
                root = root->left;
            } else {
                distanceK(root->left, K, dist + 1, result);
                root = root->right;
            }
            dist--;
        }
        if (K == 0) { result.push_back(root->val); }
        distanceK(root->left, K, 1, result);
        distanceK(root->right, K, 1, result);
        return result;
    }
};