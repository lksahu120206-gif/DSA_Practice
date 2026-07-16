class Solution {
public:
    void dfsHelper(int node, vector<vector<int>>& adj,
                   vector<int>& vis, vector<int>& ans) {

        vis[node] = 1;
        ans.push_back(node);

        for (int nbr : adj[node]) {
            if (!vis[nbr])
                dfsHelper(nbr, adj, vis, ans);
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {

        int V = adj.size();

        vector<int> vis(V, 0);
        vector<int> ans;

        dfsHelper(0, adj, vis, ans);

        return ans;
    }
};