class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {

        int V = adj.size();

        vector<int> vis(V, 0);
        vector<int> ans;

        queue<int> q;

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int nbr : adj[node]) {

                if (!vis[nbr]) {

                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }

        return ans;
    }
};