1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class Solution {
12public:
13    TreeNode* lowestCommonAncestor(TreeNode* root,
14                                   TreeNode* p,
15                                   TreeNode* q) {
16
17        while (root) {
18
19            if (p->val < root->val && q->val < root->val)
20                root = root->left;
21
22            else if (p->val > root->val && q->val > root->val)
23                root = root->right;
24
25            else
26                return root;
27        }
28
29        return nullptr;
30    }
31};