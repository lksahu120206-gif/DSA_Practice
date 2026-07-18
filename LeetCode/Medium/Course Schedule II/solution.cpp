class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &e : prerequisites) {
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            order.push_back(node);

            for (int nbr : adj[node]) {

                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if (order.size() == numCourses)
            return order;

        return {};
    }
};