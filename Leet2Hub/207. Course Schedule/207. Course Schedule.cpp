1class Solution {
2public:
3    bool dfs(int node,
4             vector<vector<int>>& adj,
5             vector<int>& vis,
6             vector<int>& pathVis) {
7
8        vis[node] = 1;
9        pathVis[node] = 1;
10
11        for (int nbr : adj[node]) {
12
13            if (!vis[nbr]) {
14                if (dfs(nbr, adj, vis, pathVis))
15                    return true;
16            }
17            else if (pathVis[nbr]) {
18                return true;
19            }
20        }
21
22        pathVis[node] = 0;   // backtrack
23        return false;
24    }
25
26    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
27
28        vector<vector<int>> adj(numCourses);
29
30        // b -> a
31        for (auto &edge : prerequisites) {
32            adj[edge[1]].push_back(edge[0]);
33        }
34
35        vector<int> vis(numCourses, 0);
36        vector<int> pathVis(numCourses, 0);
37
38        for (int i = 0; i < numCourses; i++) {
39            if (!vis[i]) {
40                if (dfs(i, adj, vis, pathVis))
41                    return false;   // cycle found
42            }
43        }
44
45        return true;    // no cycle
46    }
47};