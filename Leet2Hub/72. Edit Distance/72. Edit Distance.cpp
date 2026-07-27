1class Solution {
2public:
3    int minDistance(string word1, string word2) {
4
5        int n = word1.size();
6        int m = word2.size();
7
8        vector<int> prev(m + 1), cur(m + 1);
9
10        for (int j = 0; j <= m; j++)
11            prev[j] = j;
12
13        for (int i = 1; i <= n; i++) {
14
15            cur[0] = i;
16
17            for (int j = 1; j <= m; j++) {
18
19                if (word1[i - 1] == word2[j - 1])
20                    cur[j] = prev[j - 1];
21                else
22                    cur[j] = 1 + min({prev[j], cur[j - 1], prev[j - 1]});
23            }
24
25            prev = cur;
26        }
27
28        return prev[m];
29    }
30};