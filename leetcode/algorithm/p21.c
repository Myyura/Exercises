/**
 * Merge Two Sorted Lists 
 * Myyura
 */

/**
 * Merge two sorted linked lists and return it as a new list. The new list should 
 * be made by splicing together the nodes of the first two lists.
 *
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }

    struct ListNode* head = NULL;
    struct ListNode* p = head;
    struct ListNode* pl1 = l1;
    struct ListNode* pl2 = l2;
    for (; pl1 != NULL && pl2 != NULL; ) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        if (pl1->val < pl2->val) {
            newNode->val = pl1->val;
            pl1 = pl1->next;
        } else {
            newNode->val = pl2->val;
            pl2 = pl2->next;
        }

        if (p == NULL) {
            head = p;
        } else {
            p->next = newNode;
        }
        p = newNode;
    }

    struct ListNode* left = pl1 == NULL ? pl2 : pl1;
    for (; left != NULL; left = left->next) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = left->val;
        p->next = newNode;
        p = newNode;
    }

    return head;
}