class Solution {
public:
    long long totalScore(int hp, vector<int>& damage,
                         vector<int>& requirement) {
        int n = damage.size();
        long long points = 0;
        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; i++) {
            P[i + 1] = P[i] + damage[i];
        }
        for (int j = 0; j < n; j++) {
            long long max_allowed = min((long long)(hp - 1), (long long)hp - requirement[j]);
            if (max_allowed < 0)
                continue;
            long long min_pref = P[j + 1] - max_allowed;
            auto it = lower_bound(P.begin(), P.begin() + j + 1, min_pref);
            int valid = distance(P.begin(), it);
            if (valid <= j)
                points += (j - valid + 1);
        }

        return points;
    }
};