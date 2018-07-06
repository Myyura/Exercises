/**
 * Remove Duplicates from Sorted List II
 * Myyura
 */

/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * Example 2:
 * Input: 1->1->1->2->3
 * Output: 2->3
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode *tempHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    tempHead->next = head;
    struct ListNode *previous = tempHead, *current = head;
    int hasDupulicates = 0;
    for (; current->next != NULL;) {
        if (current->next->val == current->val) {
            hasDupulicates = 1;
            current = current->next;
            free(previous->next);
            previous->next = current;
        } else if (hasDupulicates) {
            hasDupulicates = 0;
            current = current->next;
            free(previous->next);
            previous->next = current;
        } else {
            previous = current;
            current = current->next;  
        }
    }
        
    if (hasDupulicates) {
        free(previous->next);
        previous->next = NULL;
    }
    
    struct ListNode *temp = tempHead;
    tempHead = tempHead->next;
    free(temp);
    return tempHead;
}