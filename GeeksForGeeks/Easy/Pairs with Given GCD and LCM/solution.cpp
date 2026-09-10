class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
          if (y % x != 0)
              return 0;

          int k = y / x;
          int ans = 0;

          for (int d = 1; d * d <= k; d++) {
              if (k % d == 0) {
                  int other = k / d;

                  if (__gcd(d, other) == 1) {
                      if (d == other)
                          ans += 1;
                      else
                          ans += 2;
                  }
              }
          }

          return ans;
      }
  };