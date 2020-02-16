/**
 * Myyura
 */

/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (44.77%)
 * Likes:    2383
 * Dislikes: 119
 * Total Accepted:    265.8K
 * Total Submissions: 591.2K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/** 
 * Re-build a tree from its pre-order and in-order.
 * Note that every node must be uniquely labeled.
 * 
 * Accepted but inefficient.
 */
class Codec {
public:
    struct LabeledTreeNode {
        int val;
        int label;
        LabeledTreeNode *left;
        LabeledTreeNode *right;
        LabeledTreeNode(int x, int l) : val(x), label(l), left(NULL), right(NULL) {}
    };

    LabeledTreeNode *construct_labeled_tree(TreeNode *root, int& label) {
        if (root == NULL) { return NULL; }
        
        LabeledTreeNode *current = new LabeledTreeNode(root->val, label++);
        current->left = construct_labeled_tree(root->left, label);
        current->right = construct_labeled_tree(root->right, label);
        return current;
    }

    std::string pre_order(LabeledTreeNode* root) {
        if (root == NULL) { return ""; }
        std::string result = "";
        result += std::to_string(root->val) + " " + std::to_string(root->label) + " ";
        result += pre_order(root->left);
        result += pre_order(root->right);
        return result;
    }

    std::string in_order(LabeledTreeNode* root) {
        if (root == NULL) { return ""; }
        std::string result = "";
        result += in_order(root->left);
        result += std::to_string(root->val) + " " + std::to_string(root->label) + " ";
        result += in_order(root->right);
        return result;
    }

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        int label = 0;
        LabeledTreeNode *labeled_root = construct_labeled_tree(root, label);
        std::string result;
        result = pre_order(labeled_root) + "|" + in_order(labeled_root);
        return result;
    }

    TreeNode* construct_tree(
        std::vector<std::pair<int, int>>& pre_order, 
        int& pre_index,
        std::vector<std::pair<int, int>>& in_order,
        int in_start,
        int in_end) {
        
        if (in_start > in_end) { return NULL; }

        TreeNode* current = new TreeNode(pre_order[pre_index].first);
        int current_label = pre_order[pre_index].second;
        pre_index++;

        if (in_start == in_end) { return current; }

        int in_index;
        for (int i = in_start; i <= in_end; i++) {
            if (in_order[i].first == current->val && in_order[i].second == current_label) {
                in_index = i;
                break;
            }
        }

        current->left = construct_tree(pre_order, pre_index, in_order, in_start, in_index - 1);
        current->right = construct_tree(pre_order, pre_index, in_order, in_index + 1, in_end);
        return current;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data[0] == '|') { return NULL; }

        std::vector<std::pair<int, int>> pre, in;
        int i;
        for (i = 0; data[i] != '|';) {
            int j;
            for (j = i; data[j] != ' '; j++) {}
            int value = std::stoi(data.substr(i, j - i + 1));
            i = j + 1;
            for (j = i; data[j] != ' '; j++) {}
            int label = std::stoi(data.substr(i, j - i + 1));
            pre.push_back(std::make_pair(value, label));
            i = j + 1;
        }

        for (i += 1; i < data.size();) {
            int j;
            for (j = i; data[j] != ' '; j++) {}
            int value = std::stoi(data.substr(i, j - i + 1));
            i = j + 1;
            for (j = i; data[j] != ' '; j++) {}
            int label = std::stoi(data.substr(i, j - i + 1));
            in.push_back(std::make_pair(value, label));
            i = j + 1;
        }

        int pre_index = 0;
        return construct_tree(pre, pre_index, in, 0, pre.size() - 1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
