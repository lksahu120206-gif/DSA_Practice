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
14    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
15        unordered_map<int, int> inPos;
16
17        for (int i = 0; i < inorder.size(); i++) {
18            inPos[inorder[i]] = i;
19        }
20
21        int postIndex = postorder.size() - 1;
22
23        return build(postorder, 0, inorder.size() - 1, postIndex, inPos);
24    }
25
26private:
27    TreeNode* build(vector<int>& postorder, int inStart, int inEnd,
28                    int& postIndex, unordered_map<int, int>& inPos) {
29
30        if (inStart > inEnd) {
31            return nullptr;
32        }
33
34        int rootValue = postorder[postIndex--];
35        TreeNode* root = new TreeNode(rootValue);
36
37        int rootIndex = inPos[rootValue];
38
39        // Build right first because postorder is read backwards:
40        // root -> right -> left
41        root->right = build(postorder, rootIndex + 1, inEnd, postIndex, inPos);
42        root->left = build(postorder, inStart, rootIndex - 1, postIndex, inPos);
43
44        return root;
45    }
46};