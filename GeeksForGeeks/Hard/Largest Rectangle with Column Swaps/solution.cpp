class Solution {
    public:
        int maxArea(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();

            vector<int> height(m, 0);
            int ans = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == 1)
                        height[j]++;
                    else
                        height[j] = 0;
                }
                vector<int> sorted = height;
                sort(sorted.begin(), sorted.end(), greater<int>());

                for (int j = 0; j < m; j++) {
                    int width = j + 1;
                    int area = sorted[j] * width;

                    ans = max(ans, area);
                }
            }

            return ans;
        }
    };