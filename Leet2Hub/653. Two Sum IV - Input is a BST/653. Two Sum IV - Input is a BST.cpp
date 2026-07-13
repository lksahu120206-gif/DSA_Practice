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
13    stack<TreeNode*> st;
14    bool reverse;
15
16    void pushAll(TreeNode* node) {
17        while (node) {
18            st.push(node);
19            node = reverse ? node->right : node->left;
20        }
21    }
22
23public:
24    BSTIterator(TreeNode* root, bool rev) {
25        reverse = rev;
26        pushAll(root);
27    }
28
29    int next() {
30        TreeNode* node = st.top();
31        st.pop();
32
33        if (!reverse)
34            pushAll(node->right);
35        else
36            pushAll(node->left);
37
38        return node->val;
39    }
40};
41
42class Solution {
43public:
44    bool findTarget(TreeNode* root, int k) {
45
46        BSTIterator l(root, false);
47        BSTIterator r(root, true);
48
49        int i = l.next();
50        int j = r.next();
51
52        while (i < j) {
53
54            if (i + j == k)
55                return true;
56
57            if (i + j < k)
58                i = l.next();
59            else
60                j = r.next();
61        }
62
63        return false;
64    }
65};