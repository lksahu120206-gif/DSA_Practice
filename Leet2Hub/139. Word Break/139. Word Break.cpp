1class Solution {
2public:
3    bool wordBreak(string s, vector<string>& wordDict) {
4
5        unordered_set<string> st(wordDict.begin(), wordDict.end());
6
7        int n = s.size();
8
9        vector<bool> dp(n + 1, false);
10
11        dp[0] = true;
12
13        for (int i = 1; i <= n; i++) {
14
15            for (int j = 0; j < i; j++) {
16
17                if (dp[j] &&
18                    st.count(s.substr(j, i - j))) {
19
20                    dp[i] = true;
21                    break;
22                }
23            }
24        }
25
26        return dp[n];
27    }
28};