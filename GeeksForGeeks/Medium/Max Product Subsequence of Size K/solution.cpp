class Solution {
    public:
        long long maxProduct(vector<int>& arr, int k) {
            const long long INF = (1LL << 60);

            vector<long long> mx(k + 1, -INF);
            vector<long long> mn(k + 1, INF);

            mx[0] = mn[0] = 1;

            for (int x : arr) {
                for (int j = k; j >= 1; j--) {

                    long long bestMax = mx[j];
                    long long bestMin = mn[j];

                    if (mx[j - 1] != -INF) {
                        bestMax = max(bestMax, mx[j - 1] * x);
                        bestMin = min(bestMin, mx[j - 1] * x);
                    }

                    if (mn[j - 1] != INF) {
                        bestMax = max(bestMax, mn[j - 1] * x);
                        bestMin = min(bestMin, mn[j - 1] * x);
                    }

                    mx[j] = bestMax;
                    mn[j] = bestMin;
                }
            }

            return mx[k];
        }
    };