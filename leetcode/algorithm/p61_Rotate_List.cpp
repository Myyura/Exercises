/**
 * Rotate List
 * Myyura
 */

/**
 * Given a linked list, rotate the list to the right by k places, where k is 
 * non-negative.
 * 
 * Example 1:
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * Example 2:
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int len = 0;
    struct ListNode *current = head, *last;
    for (; current != NULL && current->next != NULL; len++) {
        current = current->next;   
    }
    len += (current != NULL);
    if (len <= 1) { return head; }
    
    k %= len;
    if (k == 0) { return head; }
    
    last = current, current = head;
    for (int i = 1; i < len - k; i++) {
        current = current->next;
    }
    struct ListNode *newHead = current->next;
    current->next = NULL;
    last->next = head;
    return newHead;
}