1class Solution {
2public:
3    void dfs(int r, int c, vector<vector<char>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
8            return;
9
10        grid[r][c] = '0';
11
12        dfs(r + 1, c, grid);
13        dfs(r - 1, c, grid);
14        dfs(r, c + 1, grid);
15        dfs(r, c - 1, grid);
16    }
17
18    int numIslands(vector<vector<char>>& grid) {
19        int m = grid.size();
20        int n = grid[0].size();
21        int islands = 0;
22
23        for (int i = 0; i < m; i++) {
24            for (int j = 0; j < n; j++) {
25                if (grid[i][j] == '1') {
26                    islands++;
27                    dfs(i, j, grid);
28                }
29            }
30        }
31
32        return islands;
33    }
34};