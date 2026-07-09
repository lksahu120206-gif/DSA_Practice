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
18        if (left->val != right->val) return false;
19
20        return isMirror(left->left, right->right) &&
21               isMirror(left->right, right->left);
22    }
23
24    bool isSymmetric(TreeNode* root) {
25        if (root == nullptr) return true;
26
27        return isMirror(root->left, root->right);
28    }
29};