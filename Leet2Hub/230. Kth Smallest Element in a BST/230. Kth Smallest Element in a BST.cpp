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
14    int cnt = 0;
15    int ans = -1;
16
17    void inorder(TreeNode* root, int k) {
18        if (!root || cnt >= k)
19            return;
20
21        inorder(root->left, k);
22
23        cnt++;
24        if (cnt == k) {
25            ans = root->val;
26            return;
27        }
28
29        inorder(root->right, k);
30    }
31
32    int kthSmallest(TreeNode* root, int k) {
33        inorder(root, k);
34        return ans;
35    }
36};