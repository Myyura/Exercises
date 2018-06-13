/**
 * Merge k Sorted Lists  
 * Myyura 
 */

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and 
 * describe its complexity.
 * 
 * Example:
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Basic idea:
 * Compare the head of every list and get the node with minimum value;
 * To find the minimum one, we use min-heap to maintain the k heads.
 * 
 * Time complexity : O(nlogk) where n is the total number of nodes.
 */

int currentSize = 0;
struct ListNode* heap[20000];

void insert(struct ListNode* node) {
    if (node == NULL) {
        return;
    }

    if (currentSize == 20000) {
        printf("Full.\n");
        return;
    }

    if (currentSize == 0) {
        heap[++currentSize] = node;
        return;
    }

    int i;
    for (i = ++currentSize; i > 1 && heap[i / 2]->val > node->val; i /= 2) {
        heap[i] = heap[i / 2];
    }
    heap[i] = node;
}

struct ListNode* delete(void) {
    if (currentSize == 0) {
        printf("Empty.\n");
        return NULL;
    }

    struct ListNode* min = heap[1];
    struct ListNode* last = heap[currentSize--];
    int i, child;
    for (i = 1; i * 2 <= currentSize; i = child) {
        child = i * 2;
        if (child + 1 <= currentSize && heap[child + 1]->val < heap[child]->val) {
            child = child + 1;
        }

        if (last->val > heap[child]->val) {
            heap[i] = heap[child];
        } else {
            break;
        }
    }
    heap[i] = last;

    return min;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) { return NULL; }
    for (int i = 0; i < listsSize; i++) {
        insert(lists[i]);
    }

    struct ListNode* head = NULL;
    struct ListNode* current;
    for (; currentSize > 0;) {
        struct ListNode* node = delete();
        if (head == NULL) {
            head = node;
        } else {
            current->next = node;
        }
        current = node;

        if (node->next != NULL) {
            insert(node->next);
        }
    }

    return head;
}
