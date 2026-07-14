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
14    void flatten(TreeNode* root) {
15
16        TreeNode* cur = root;
17
18        while (cur) {
19
20            if (cur->left) {
21
22                TreeNode* prev = cur->left;
23
24                while (prev->right)
25                    prev = prev->right;
26
27                prev->right = cur->right;
28                cur->right = cur->left;
29                cur->left = nullptr;
30            }
31
32            cur = cur->right;
33        }
34    }
35};