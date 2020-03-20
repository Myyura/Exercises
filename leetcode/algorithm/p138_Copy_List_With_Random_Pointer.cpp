/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (32.94%)
 * Likes:    2598
 * Dislikes: 588
 * Total Accepted:    355.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]\r'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * The Linked List is represented in the input/output as a list of n nodes.
 * Each node is represented as a pair of [val, random_index] where:
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) where random
 * pointer points to, or null if it does not point to any node.
 * 
 * 
 * Example 1:
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * Example 2:
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * 
 * Example 3:
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * 
 * Example 4:
 * Input: head = []
 * Output: []
 * Explanation: Given linked list is empty (null pointer), so return null.
 * 
 * 
 * Constraints:
 * -10000 <= Node.val <= 10000
 * Node.random is null or pointing to a node in the linked list.
 * Number of Nodes will not exceed 1000.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    /* O(n^2) time complexity, O(1) extra space, accepted */
    Node* copyRandomList(Node* head) {
        if (head == NULL) { return NULL; }

        Node* new_head = new Node(head->val);
        for (Node *p = head->next, *np = new_head; p != NULL; p = p->next) {
            np->next = new Node(p->val);
            np = np->next;
        }

        for (Node *p = head, *np = new_head; np != NULL;) {
            int pos = 0, not_null = 0;
            // if a node p, whose random pointer points at the ith node,
            // then after a deep copy, the random pointer of the corresponding 
            // pointer of p, we call np, will also point at the ith node in the
            // new list
            for (Node *rp = head; rp != NULL; rp = rp->next) {
                if (rp == p->random) {
                    not_null = 1;
                    break;
                }
                pos++;
            }
            
            Node *random_for_np;
            if (not_null) {
                for (random_for_np = new_head; pos > 0; pos--) {
                    random_for_np = random_for_np->next;
                }
            } else {
                random_for_np = NULL;
            }

            np->random = random_for_np;
            np = np->next;
            p = p->next;
        }

        return new_head;
    }
};
