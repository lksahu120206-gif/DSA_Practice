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
14    bool check(TreeNode* root, long long low, long long high) {
15        if (!root)
16            return true;
17
18        if (root->val <= low || root->val >= high)
19            return false;
20
21        return check(root->left, low, root->val) &&
22               check(root->right, root->val, high);
23    }
24
25    bool isValidBST(TreeNode* root) {
26        return check(root, LLONG_MIN, LLONG_MAX);
27    }
28};