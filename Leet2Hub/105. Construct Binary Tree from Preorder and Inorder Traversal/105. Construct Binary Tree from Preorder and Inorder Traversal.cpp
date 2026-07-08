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
14    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
15        unordered_map<int, int> inPos;
16
17        for (int i = 0; i < inorder.size(); i++) {
18            inPos[inorder[i]] = i;
19        }
20
21        int preIndex = 0;
22
23        return build(preorder, 0, inorder.size() - 1, preIndex, inPos);
24    }
25
26private:
27    TreeNode* build(vector<int>& preorder, int inStart, int inEnd,
28                    int& preIndex, unordered_map<int, int>& inPos) {
29
30        if (inStart > inEnd) {
31            return nullptr;
32        }
33
34        int rootValue = preorder[preIndex++];
35        TreeNode* root = new TreeNode(rootValue);
36
37        int rootIndex = inPos[rootValue];
38
39        root->left = build(preorder, inStart, rootIndex - 1, preIndex, inPos);
40        root->right = build(preorder, rootIndex + 1, inEnd, preIndex, inPos);
41
42        return root;
43    }
44};