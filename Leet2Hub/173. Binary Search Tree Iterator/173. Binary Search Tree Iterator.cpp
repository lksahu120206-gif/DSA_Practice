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
12class BSTIterator {
13
14    stack<TreeNode*> st;
15
16    void pushAll(TreeNode* node) {
17        while (node) {
18            st.push(node);
19            node = node->left;
20        }
21    }
22
23public:
24    BSTIterator(TreeNode* root) {
25        pushAll(root);
26    }
27
28    int next() {
29
30        TreeNode* node = st.top();
31        st.pop();
32
33        pushAll(node->right);
34
35        return node->val;
36    }
37
38    bool hasNext() {
39        return !st.empty();
40    }
41};
42
43/**
44 * Your BSTIterator object will be instantiated and called as such:
45 * BSTIterator* obj = new BSTIterator(root);
46 * int param_1 = obj->next();
47 * bool param_2 = obj->hasNext();
48 */