1class TrieNode {
2public:
3    TrieNode* child[26];
4    bool isEnd;
5
6    TrieNode() {
7        isEnd = false;
8        for (int i = 0; i < 26; i++)
9            child[i] = nullptr;
10    }
11};
12
13class Trie {
14    TrieNode* root;
15
16public:
17    Trie() {
18        root = new TrieNode();
19    }
20
21    void insert(string word) {
22        TrieNode* node = root;
23
24        for (char c : word) {
25            int idx = c - 'a';
26
27            if (node->child[idx] == nullptr)
28                node->child[idx] = new TrieNode();
29
30            node = node->child[idx];
31        }
32
33        node->isEnd = true;
34    }
35
36    bool search(string word) {
37        TrieNode* node = root;
38
39        for (char c : word) {
40            int idx = c - 'a';
41
42            if (node->child[idx] == nullptr)
43                return false;
44
45            node = node->child[idx];
46        }
47
48        return node->isEnd;
49    }
50
51    bool startsWith(string prefix) {
52        TrieNode* node = root;
53
54        for (char c : prefix) {
55            int idx = c - 'a';
56
57            if (node->child[idx] == nullptr)
58                return false;
59
60            node = node->child[idx];
61        }
62
63        return true;
64    }
65};