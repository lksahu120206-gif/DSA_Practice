1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21
22class Solution {
23public:
24
25    unordered_map<Node*, Node*> mp;
26
27    Node* dfs(Node* node) {
28
29        if (mp.count(node))
30            return mp[node];
31
32        Node* clone = new Node(node->val);
33
34        mp[node] = clone;
35
36        for (Node* nbr : node->neighbors) {
37            clone->neighbors.push_back(dfs(nbr));
38        }
39
40        return clone;
41    }
42
43    Node* cloneGraph(Node* node) {
44
45        if (!node)
46            return nullptr;
47
48        return dfs(node);
49    }
50};