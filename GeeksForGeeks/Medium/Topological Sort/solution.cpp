class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (int nbr : adj[node]) {

                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        return topo;
    }
};