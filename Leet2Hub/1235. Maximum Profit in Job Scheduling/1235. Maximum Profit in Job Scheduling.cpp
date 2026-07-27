1class Solution {
2public:
3    int jobScheduling(vector<int>& startTime,
4                      vector<int>& endTime,
5                      vector<int>& profit) {
6
7        int n = startTime.size();
8
9        vector<tuple<int,int,int>> jobs;
10
11        for (int i = 0; i < n; i++)
12            jobs.push_back({startTime[i], endTime[i], profit[i]});
13
14        sort(jobs.begin(), jobs.end());
15
16        vector<int> starts;
17        for (auto &job : jobs)
18            starts.push_back(get<0>(job));
19
20        vector<int> dp(n + 1, 0);
21
22        for (int i = n - 1; i >= 0; i--) {
23
24            auto [s, e, p] = jobs[i];
25
26            int next = lower_bound(starts.begin(), starts.end(), e) - starts.begin();
27
28            dp[i] = max(dp[i + 1], p + dp[next]);
29        }
30
31        return dp[0];
32    }
33};