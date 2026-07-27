class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {

        vector<bool> dp(sum + 1, false);

        dp[0] = true;

        for(int x : arr){

            for(int j = sum; j >= x; j--)
                dp[j] = dp[j] || dp[j - x];
        }

        return dp[sum];
    }
};