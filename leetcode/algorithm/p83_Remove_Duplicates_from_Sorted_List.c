/**
 * Remove Duplicates from Sorted List
 * Myyura
 */

/**
 * Given a sorted linked list, delete all duplicates such that each element 
 * appear only once.
 * 
 * Example 1:
 * Input: 1->1->2
 * Output: 1->2
 * 
 * Example 2:
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) { return head; }
    struct ListNode *curNode = head;
    for (; curNode->next != NULL;) {
        if (curNode->val == curNode->next->val) {
            struct ListNode *temp = curNode->next;
            curNode->next = curNode->next->next;
            free(temp);
            continue;
        }
        
        curNode = curNode->next;
    }
    
    return head;
}