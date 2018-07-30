/**
 * Convert Sorted List to Binary Search Tree
 * Myyura
 */

/**
 * Given a singly linked list where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree in 
 * which the depth of the two subtrees of every node never differ by more than 1.
 * 
 * Example:
 * Given the sorted linked list: [-10,-3,0,5,9],
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following 
 * height balanced BST:
 * 
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums, int left, int right) {
        if (left > right) { return NULL; }
        int mid = (left + right) / 2;
        TreeNode *current = new TreeNode(nums[mid]);
        current->left = sortedArrayToBST(nums, left, mid - 1);
        current->right = sortedArrayToBST(nums, mid + 1, right);
        return current;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> nums;
        for (ListNode* current = head; current != NULL; current = current->next) { 
            nums.push_back(current->val); 
        }
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};