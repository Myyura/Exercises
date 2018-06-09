/**
 * Add Two Numbers  
 * Myyura
 */

/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single 
 * digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
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