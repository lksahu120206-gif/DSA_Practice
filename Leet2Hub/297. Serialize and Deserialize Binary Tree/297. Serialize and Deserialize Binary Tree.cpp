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
11class Codec {
12public:
13
14    // Encodes a tree to a single string.
15    string serialize(TreeNode* root) {
16
17        if (!root)
18            return ;
19
20        queue<TreeNode*> q;
21        q.push(root);
22
23        string s;
24
25        while (!q.empty()) {
26
27            TreeNode* node = q.front();
28            q.pop();
29
30            if (node) {
31                s += to_string(node->val) + ,;
32                q.push(node->left);
33                q.push(node->right);
34            }
35            else {
36                s += N,;
37            }
38        }
39
40        return s;
41    }
42
43    // Decodes your encoded data to tree.
44    TreeNode* deserialize(string data) {
45
46        if (data.empty())
47            return nullptr;
48
49        stringstream ss(data);
50        string str;
51
52        getline(ss, str, ',');
53        TreeNode* root = new TreeNode(stoi(str));
54
55        queue<TreeNode*> q;
56        q.push(root);
57
58        while (!q.empty()) {
59
60            TreeNode* node = q.front();
61            q.pop();
62
63            // Left child
64            getline(ss, str, ',');
65            if (str != N) {
66                node->left = new TreeNode(stoi(str));
67                q.push(node->left);
68            }
69
70            // Right child
71            getline(ss, str, ',');
72            if (str != N) {
73                node->right = new TreeNode(stoi(str));
74                q.push(node->right);
75            }
76        }
77
78        return root;
79    }
80};
81
82/**
83 * Your Codec object will be instantiated and called as such:
84 * Codec ser, deser;
85 * TreeNode* ans = deser.deserialize(ser.serialize(root));
86 */