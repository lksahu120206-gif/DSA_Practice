1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4
5        vector<vector<int>> adj(numCourses);
6        vector<int> indegree(numCourses, 0);
7
8        for (auto &edge : prerequisites) {
9            adj[edge[1]].push_back(edge[0]);
10            indegree[edge[0]]++;
11        }
12
13        queue<int> q;
14
15        for (int i = 0; i < numCourses; i++) {
16            if (indegree[i] == 0)
17                q.push(i);
18        }
19
20        int count = 0;
21
22        while (!q.empty()) {
23            int node = q.front();
24            q.pop();
25            count++;
26
27            for (int nbr : adj[node]) {
28                indegree[nbr]--;
29                if (indegree[nbr] == 0)
30                    q.push(nbr);
31            }
32        }
33
34        return count == numCourses;
35    }
36};