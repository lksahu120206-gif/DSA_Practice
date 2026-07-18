1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4
5        vector<vector<int>> adj(numCourses);
6        vector<int> indegree(numCourses, 0);
7
8        // Build graph
9        for (auto &e : prerequisites) {
10            adj[e[1]].push_back(e[0]); // prerequisite -> course
11            indegree[e[0]]++;
12        }
13
14        queue<int> q;
15
16        // Push all courses with no prerequisites
17        for (int i = 0; i < numCourses; i++) {
18            if (indegree[i] == 0)
19                q.push(i);
20        }
21
22        int completed = 0;
23
24        while (!q.empty()) {
25
26            int node = q.front();
27            q.pop();
28            completed++;
29
30            for (int nbr : adj[node]) {
31                indegree[nbr]--;
32
33                if (indegree[nbr] == 0)
34                    q.push(nbr);
35            }
36        }
37
38        return completed == numCourses;
39    }
40};