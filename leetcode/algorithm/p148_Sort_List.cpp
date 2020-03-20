/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (39.70%)
 * Likes:    2208
 * Dislikes: 113
 * Total Accepted:    237K
 * Total Submissions: 596K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
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
    /* Merge sort, O(nlogn) time, O(n) extra space since recursion is used */
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        ListNode* new_head;
        if (left == NULL) { 
            new_head = right;
        } else if (right == NULL) {
            new_head = left;
        } else {
            if (left->val < right->val) {
                new_head = left;
                left = left->next;
            } else {
                new_head = right;
                right = right->next;
            }

            for (ListNode* current = new_head; left || right; current = current->next) {
                if (left && right) {
                    if (left->val < right->val) {
                        current->next = left;
                        left = left->next;
                    } else {
                        current->next = right;
                        right = right->next;
                    }
                } else {
                    if (left) {
                        current->next = left;
                    }
                    if (right) {
                        current->next = right;
                    }
                    break;
                }
            }
        }
        
        return new_head;
    }
};
