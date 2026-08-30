class Solution {
public:
    vector<int> getMarks(vector<int>& l, vector<int>& r,
                         vector<int>& rank) {

        int m = l.size();

        vector<long long> prefix(m);

        prefix[0] = r[0] - l[0] + 1;

        for (int i = 1; i < m; i++) {
            prefix[i] = prefix[i - 1] + (r[i] - l[i] + 1);
        }

        vector<int> ans;

        for (int k : rank) {

            int low = 0;
            int high = m - 1;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (prefix[mid] >= k)
                    high = mid;
                else
                    low = mid + 1;
            }

            int i = low;

            long long before = (i == 0 ? 0 : prefix[i - 1]);

            long long offset = k - before - 1;

            ans.push_back(l[i] + offset);
        }

        return ans;
    }
};