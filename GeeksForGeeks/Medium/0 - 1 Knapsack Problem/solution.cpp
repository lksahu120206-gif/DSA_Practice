class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < wt.size(); i++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }

        return dp[W];
    }
};