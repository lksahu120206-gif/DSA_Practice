1class Solution {
2public:
3    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
4
5        vector<vector<int>> adj(numCourses);
6        vector<int> indegree(numCourses, 0);
7
8        for (auto &e : prerequisites) {
9            adj[e[1]].push_back(e[0]);
10            indegree[e[0]]++;
11        }
12
13        queue<int> q;
14
15        for (int i = 0; i < numCourses; i++) {
16            if (indegree[i] == 0)
17                q.push(i);
18        }
19
20        vector<int> order;
21
22        while (!q.empty()) {
23
24            int node = q.front();
25            q.pop();
26
27            order.push_back(node);
28
29            for (int nbr : adj[node]) {
30
31                indegree[nbr]--;
32
33                if (indegree[nbr] == 0)
34                    q.push(nbr);
35            }
36        }
37
38        if (order.size() == numCourses)
39            return order;
40
41        return {};
42    }
43};