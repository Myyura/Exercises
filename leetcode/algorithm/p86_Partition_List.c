/**
 * Partition List
 * Myyura
 */

/**
 * Given a linked list and a value x, partition it such that all nodes less than 
 * x come before nodes greaterEqual than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two 
 * partitions.
 * 
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Extra O(n) space
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *less = NULL, *greaterEqual = NULL;
    struct ListNode *lessHead = NULL, *greaterEqualHead = NULL;
    for (; head != NULL; head = head->next) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = head->val, temp->next = NULL;
        
        if (head->val < x) {
            if (less != NULL) { less->next = temp; }
            if (less == NULL) { lessHead = temp; }
            less = temp; 
        }
        
        if (head->val >= x) {
            if (greaterEqual != NULL) { greaterEqual->next = temp; }
            if (greaterEqual == NULL) { greaterEqualHead = temp; }
            greaterEqual = temp;
        }
    }
    
    if (less != NULL) { less->next = greaterEqualHead; }
    if (lessHead == NULL) { return greaterEqualHead; }
    return lessHead;
}

// In place
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *less = NULL, *greaterEqual = NULL;
    struct ListNode *lessHead = NULL, *greaterEqualHead = NULL;
    for (; head != NULL; head = head->next) {
        if (head->val < x) {
            if (less != NULL) { 
                less->next = head;
                less = head;
            } else {
                lessHead = less = head;
            }
        }
        
        if (head->val >= x) {
            if (greaterEqual != NULL) { 
                greaterEqual->next = head;
                greaterEqual = head;
            } else {
                greaterEqualHead = greaterEqual = head;
            }
        }
    }
    
    if (greaterEqual != NULL) { greaterEqual->next = NULL; }
    if (less != NULL) { less->next = greaterEqualHead; }
    if (lessHead == NULL) { return greaterEqualHead; }
    return lessHead;
}