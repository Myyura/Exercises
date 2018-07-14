/**
 * Unique Binary Search Trees
 * Myyura
 */

/**
 * Given n, how many structurally unique BST's (binary search trees) that store 
 * values 1 ... n?
 * 
 * Example:
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

/**
 * When root is fixed, every combination of unique left/right subtrees forms
 * a unique BST.
 * 
 * Let trees(n) denote the number of unique BST with a given integer n.
 * Then trees(n) = trees(0) * trees(n - 1)
 *               + trees(1) * trees(n - 2)
 *               + ...
 *               + trees(n - 1) * trees(0)
 */
int numTrees(int n) {
    int trees[n + 1];
    for (int i = 0; i <= n; i++) { trees[i] = 0; }
    
    trees[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            trees[i] += trees[j] * trees[i - j - 1];
        }
    }
    
    return trees[n];
}