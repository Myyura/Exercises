/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (41.50%)
 * Likes:    1523
 * Dislikes: 135
 * Total Accepted:    310.5K
 * Total Submissions: 742.5K
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition:
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * Follow up:
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not
 * count as extra space for this problem.
 * 
 * Example 1:
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node, just like
 * in Figure B. The serialized output is in level order as connected by the
 * next pointers, with '#' signifying the end of each level.
 * 
 * Constraints:
 * The number of nodes in the given tree is less than 4096.
 * -1000 <= node.val <= 1000
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    /* BFS, O(n) memory, O(n) time, accepted */
    Node* connect(Node* root) {
        if (root == NULL) { return NULL; }

        std::queue<Node*> q;
        int n = 2, i = 1;
        for (q.push(root); !q.empty(); i++) {
            Node *current = q.front();
            q.pop();
            if (current->left) { q.push(current->left); }
            if (current->right) { q.push(current->right); }
            if (i == n - 1) {
                n *= 2;
                current->next = NULL;
            } else {
                current->next = q.front();
            }
        }

        return root;
    }
};
