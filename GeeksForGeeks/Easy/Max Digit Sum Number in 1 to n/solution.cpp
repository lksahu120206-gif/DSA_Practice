class Solution {
public:
    int findMax(int n) {
        string s = to_string(n);

        int bestNum = n;
        int bestSum = 0;

        for (char c : s)
            bestSum += c - '0';

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '0')
                continue;

            string t = s;
            t[i]--;
            for (int j = i + 1; j < s.size(); j++)
                t[j] = '9';

            int candidate = stoi(t);

            int sum = 0;
            for (char c : t)
                sum += c - '0';

            if (sum > bestSum ||
                (sum == bestSum && candidate > bestNum)) {
                bestSum = sum;
                bestNum = candidate;
            }
        }

        return bestNum;
    }
};