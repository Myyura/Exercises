/**
 * Swap Nodes in Pairs
 * Myyura
 */

/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Note:
 * Your algorithm should use only constant extra space.
 * You may not modify the values in the list's nodes, only nodes itself may be 
 * changed.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *resultHead = head->next;
    head->next = head->next->next;
    resultHead->next = head;

    if (head->next == NULL || head->next->next == NULL) { 
        return resultHead; 
    }

    struct ListNode *first = head, *second = first->next, *third = second->next;
    for (; ;) {
        first->next = second->next;
        second->next = third->next;
        third->next = second;
        if (second->next == NULL || second->next->next == NULL) {
            return resultHead;
        }
        first = second, second = second->next, third = second->next;
    }

    return resultHead;
}