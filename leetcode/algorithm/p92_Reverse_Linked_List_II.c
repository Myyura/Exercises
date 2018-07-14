/**
 * Reverse Linked List II
 * Myyura
 */

/**
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (head == NULL || m == n) { return head; }
    struct ListNode *previous = head, *start = previous;
    for (int i = 1; i < m && previous != NULL; i++) { 
        if (start != previous) { start = start->next; }
        previous = previous->next; 
    }

    struct ListNode *current = previous->next, *firstOne = previous;
    for (int i = m; i < n; i++) {
        struct ListNode *temp = current->next;
        current->next = previous;
        previous = current, current = temp;
    }

    firstOne->next = current;
    if (m == 1) { return previous; }
    start->next = previous;
    return head;
}