/**
 * Myyura
 */

/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (39.40%)
 * Likes:    476
 * Dislikes: 515
 * Total Accepted:    170.5K
 * Total Submissions: 431.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 * 
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 * 
 * Algorithm of Insertion Sort:
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 * 
 * Example 1:
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * Example 2:
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /* Self-Deception, accepted */
    // ListNode* insertionSortList(ListNode* head) {
    //     if (head == NULL || head->next == NULL) { return head; }

    //     std::vector<ListNode*> nodes;
    //     for (ListNode *current = head; current != NULL; current = current->next) {
    //         nodes.push_back(current);
    //     }

    //     for (int i = nodes.size() - 2; i >= 0; i--) {
    //         for (int j = i; j + 1 < nodes.size(); j++) {
    //             if (nodes[j]->val > nodes[j + 1]->val) {
    //                 ListNode* temp = nodes[j];
    //                 nodes[j] = nodes[j + 1];
    //                 nodes[j + 1] = temp;
    //             } else {
    //                 break;
    //             }
    //         }
    //     }

    //     for (int i = 0; i < nodes.size() - 1; i++) {
    //         nodes[i]->next = nodes[i + 1];
    //     }
    //     nodes[nodes.size() - 1]->next = NULL;

    //     return nodes[0];
    // }

    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) { return head; }

        ListNode *prev = head, *current = head->next;
        for (; current != NULL;) {
            if (current->val < prev->val) {
                prev->next = current->next;

                if (head->val >= current->val) {
                    current->next = head;
                    head = current;
                } else {
                    ListNode *temp = head;
                    for (; temp->next->val <= current->val; temp = temp->next) {}
                    current->next = temp->next;
                    temp->next = current;
                }

                current = prev->next;
            } else {
                current = current->next;
                prev = prev->next;
            }
        }

        return head;
    }
};
