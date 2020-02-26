/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (36.84%)
 * Likes:    1261
 * Dislikes: 167
 * Total Accepted:    224.5K
 * Total Submissions: 606K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * Given a binary tree
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
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B. The serialized output is in level order as connected by the next
 * pointers, with '#' signifying the end of each level.
 * 
 * Constraints:
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
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

        std::queue<Node*> q1, q2;
        bool is_q1 = true;
        for (q1.push(root); !q1.empty() || !q2.empty();) {
            Node *current;
            if (is_q1) {
                current = q1.front();
                q1.pop();
                if (current->left) { q2.push(current->left); }
                if (current->right) { q2.push(current->right); }
                if (q1.empty()) {
                    current->next = NULL;
                    is_q1 = false;
                } else {
                    current->next = q1.front();
                }
            } else {
                current = q2.front();
                q2.pop();
                if (current->left) { q1.push(current->left); }
                if (current->right) { q1.push(current->right); }
                if (q2.empty()) {
                    current->next = NULL;
                    is_q1 = true;
                } else {
                    current->next = q2.front();
                }
            }
        }

        return root;
    }
};

