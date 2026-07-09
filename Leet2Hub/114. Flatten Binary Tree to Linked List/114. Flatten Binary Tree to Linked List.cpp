1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* previous = nullptr;
15
16    void flatten(TreeNode* root) {
17        if (root == nullptr) return;
18
19        flatten(root->right);
20        flatten(root->left);
21
22        root->right = previous;
23        root->left = nullptr;
24
25        previous = root;
26    }
27};