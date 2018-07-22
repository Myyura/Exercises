/**
 * Reverse Linked List
 * Myyura
 */

/**
 * Reverse a singly linked list.
 * 
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    struct ListNode *current = head->next, *previous = head;
    for (head->next = NULL; current != NULL;) {
        struct ListNode *temp = current->next;
        current->next = previous;
        previous = current, current = temp;
    }
    
    return previous;
}
