/**
 * Remove Nth Node From End of List 
 * Myyura
 */

/**
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * 
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 
 * Note: Given n will always be valid.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *last = head;
    for (int i = 1; i < n; i++) { last = last->next; }
    
    if (last->next == NULL) {
        struct ListNode *temp = head->next;
        free(head);
        return temp;
    }

    last = last->next;
    struct ListNode *nthFromEnd = head;
    for (; last->next != NULL; last = last->next, nthFromEnd = nthFromEnd->next)
        ;

    struct ListNode *temp = nthFromEnd->next;
    nthFromEnd->next = nthFromEnd->next->next;
    free(temp);

    return head;
}