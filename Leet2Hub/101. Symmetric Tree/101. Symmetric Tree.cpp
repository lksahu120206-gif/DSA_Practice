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
14    bool isMirror(TreeNode* left, TreeNode* right) {
15        if (left == nullptr && right == nullptr) return true;
16        if (left == nullptr || right == nullptr) return false;
17
18        return left->val == right->val &&
19               isMirror(left->left, right->right) &&
20               isMirror(left->right, right->left);
21    }
22
23    bool isSymmetric(TreeNode* root) {
24        if (root == nullptr) return true;
25
26        return isMirror(root->left, root->right);
27    }
28};