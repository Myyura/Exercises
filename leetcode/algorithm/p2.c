/**
 * Add Two Numbers  
 * Myyura
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;
    struct ListNode* curNode = dummyHead;
    int carry = 0;
    for (struct ListNode *tempL1 = l1, *tempL2 = l2; tempL1 || tempL2;) {
        int valueL1 = tempL1 ? tempL1->val : 0;
        int valueL2 = tempL2 ? tempL2->val : 0;
        int sum = carry + valueL1 + valueL2;
        carry = sum / 10;
        curNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curNode->next->val = sum % 10;
        curNode->next->next = NULL;

        curNode = curNode->next;
        tempL1 = tempL1 ? tempL1->next : NULL;
        tempL2 = tempL2 ? tempL2->next : NULL;
    }

    if (carry > 0) {
        curNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curNode->next->val = carry;
        curNode->next->next = NULL;
    }

    return dummyHead->next;
}