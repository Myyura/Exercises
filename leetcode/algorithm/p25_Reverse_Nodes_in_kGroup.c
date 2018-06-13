/**
 * Reverse Nodes in k-Group
 * Myyura
 */

/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return 
 * its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the linked 
 * list. If the number of nodes is not a multiple of k then left-out nodes in the 
 * end should remain as it is.
 * 
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be 
 * changed.
 */

struct ListNode* reverseList(struct ListNode *l, int k) {
    if (k < 2) { return l; }

    int listSize = 0;
    for (struct ListNode *it = l; listSize < k; it = it->next, listSize++) {
        if (it == NULL) { return l; }
    }
    struct ListNode *pPre = l, *p = pPre->next;
    for (int i = 0; i < k - 1; i++) {
        struct ListNode *temp = p->next;
        p->next = pPre;
        pPre = p;
        p = temp;
    }
    l->next = p;
    
    return pPre;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *newHead = reverseList(head, k);
    struct ListNode *preCurHead = head, *lastPreHead = NULL;
    for (int i = 0; preCurHead != NULL && preCurHead != lastPreHead; i++) {
        if (i % k == 0) {
            struct ListNode *temp = preCurHead->next;
            lastPreHead = preCurHead;
            preCurHead->next = reverseList(preCurHead->next, k);
            preCurHead = temp;
        }
    }

    return newHead;
}