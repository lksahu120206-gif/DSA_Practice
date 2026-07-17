1class Solution {
2public:
3    bool dfs(int node, vector<vector<int>>& adj,
4             vector<int>& vis, vector<int>& pathVis) {
5
6        vis[node] = 1;
7        pathVis[node] = 1;
8
9        for (int nbr : adj[node]) {
10            if (!vis[nbr]) {
11                if (dfs(nbr, adj, vis, pathVis))
12                    return true;
13            }
14            else if (pathVis[nbr]) {
15                return true;
16            }
17        }
18
19        pathVis[node] = 0;
20        return false;
21    }
22
23    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
24
25        vector<vector<int>> adj(numCourses);
26
27        for (auto &e : prerequisites)
28            adj[e[1]].push_back(e[0]);
29
30        vector<int> vis(numCourses, 0);
31        vector<int> pathVis(numCourses, 0);
32
33        for (int i = 0; i < numCourses; i++) {
34            if (!vis[i]) {
35                if (dfs(i, adj, vis, pathVis))
36                    return false;
37            }
38        }
39
40        return true;
41    }
42};