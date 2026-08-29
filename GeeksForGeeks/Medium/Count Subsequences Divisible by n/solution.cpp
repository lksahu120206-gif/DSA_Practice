class Solution {
  public:
      int countSubsequences(string s, int n) {
          const int MOD = 1000000007;

          vector<long long> dp(n, 0);

          for (char ch : s) {
              int d = ch - '0';

              vector<long long> next = dp;

              next[d % n]++;
              for (int r = 0; r < n; r++) {
                  if (dp[r] == 0)
                      continue;

                  int newR = (r * 10 + d) % n;

                  next[newR] = (next[newR] + dp[r]) % MOD;
              }
              for (int r = 0; r < n; r++) {
                  next[r] %= MOD;
              }

              dp = next;
          }

          return dp[0];
      }
  };