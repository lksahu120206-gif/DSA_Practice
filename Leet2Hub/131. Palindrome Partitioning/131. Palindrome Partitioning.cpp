1class Solution {
2public:
3    vector<vector<string>> ans;
4    vector<string> path;
5
6    void dfs(int start, string &s, vector<vector<bool>> &pal) {
7        if (start == s.size()) {
8            ans.push_back(path);
9            return;
10        }
11
12        for (int end = start; end < s.size(); end++) {
13            if (!pal[start][end]) continue;
14
15            path.push_back(s.substr(start, end - start + 1));
16            dfs(end + 1, s, pal);
17            path.pop_back();
18        }
19    }
20
21    vector<vector<string>> partition(string s) {
22        int n = s.size();
23
24        vector<vector<bool>> pal(n, vector<bool>(n, false));
25
26        for (int i = n - 1; i >= 0; i--) {
27            for (int j = i; j < n; j++) {
28                if (s[i] == s[j] &&
29                    (j - i <= 2 || pal[i + 1][j - 1])) {
30                    pal[i][j] = true;
31                }
32            }
33        }
34
35        dfs(0, s, pal);
36        return ans;
37    }
38};