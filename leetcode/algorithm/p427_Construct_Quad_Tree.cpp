/**
 * Myyura
 */

/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 *
 * https://leetcode.com/problems/construct-quad-tree/description/
 *
 * algorithms
 * Medium (60.13%)
 * Likes:    208
 * Dislikes: 391
 * Total Accepted:    18.9K
 * Total Submissions: 31.5K
 * Testcase Example:  '[[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]'
 *
 * We want to use quad trees to store an N x N boolean grid. Each cell in the
 * grid can only be true or false. The root node represents the whole grid. For
 * each node, it will be subdivided into four children nodes until the values
 * in the region it represents are all the same.
 * 
 * Each node has another two boolean attributes : isLeaf and val. isLeaf is
 * true if and only if the node is a leaf node. The val attribute for a leaf
 * node contains the value of the region it represents.
 * 
 * Your task is to use a quad tree to represent a given grid. The following
 * example may help you understand the problem better:
 * 
 * Given the 8 x 8 grid below, we want to construct the corresponding quad
 * tree:
 * 
 * It can be divided according to the definition above:
 * 
 * The corresponding quad tree should be as following, where each node is
 * represented as a (isLeaf, val) pair.
 * 
 * For the non-leaf nodes, val can be arbitrary, so it is represented as *.
 * 
 * Note:
 * N is less than 1000 and guaranteened to be a power of 2.
 * If you want to know more about the quad tree, you can refer to its wiki.
 */

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct_helper(
        std::vector<std::vector<int>>& grid,
        int left, int top, int n) {

        if (n == 0) { return NULL; }

        bool value = grid[left][top], is_same = true;
        for (int i = left; i < n + left; i++) {
            for (int j = top; j < n + top; j++) {
                if (grid[i][j] != value) {
                    is_same = false; 
                    break;
                }
            }
        }

        Node *new_node = new Node();
        if (is_same) {
            // when n == 1, is_same must be true.
            new_node->topLeft = new_node->topRight = new_node->bottomLeft = new_node->bottomRight = NULL;
            new_node->val = value;
            new_node->isLeaf = true;
        } else {
            new_node->isLeaf = false;
            new_node->val = false;
            int n1 = n / 2;
            int left1 = left, left2 = left, left3 = left + n1, left4 = left + n1;
            int top1 = top, top2 = top + n1, top3 = top, top4 = top + n1;
            new_node->topLeft = construct_helper(grid, left1, top1, n1);
            new_node->topRight = construct_helper(grid, left2, top2, n1);
            new_node->bottomLeft = construct_helper(grid, left3, top3, n1);
            new_node->bottomRight = construct_helper(grid, left4, top4, n1);
        }
        
        return new_node;
    }

    Node* construct(std::vector<std::vector<int>>& grid) {
        return construct_helper(grid, 0, 0, grid.size());
    }
};

