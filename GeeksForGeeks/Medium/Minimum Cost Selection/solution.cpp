class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> dp(3);

        for (int j = 0; j < 3; j++) {
            dp[j] = mat[0][j];
        }

        for (int i = 1; i < n; i++) {
            vector<int> newdp(3);

            newdp[0] = mat[i][0] + min(dp[1], dp[2]);
            newdp[1] = mat[i][1] + min(dp[0], dp[2]);
            newdp[2] = mat[i][2] + min(dp[0], dp[1]);

            dp = newdp;
        }

        return min({dp[0], dp[1], dp[2]});
    }
};