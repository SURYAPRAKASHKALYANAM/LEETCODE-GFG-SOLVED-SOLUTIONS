class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        auto comp = [&](vector<int>& p1, vector<int>& p2) {
            if (p1[0] == p2[0])
                return p1[1] > p2[1];
            return p1[0] < p2[0];
        };

        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> sub;

        for (auto& envelope : envelopes) {
            if (sub.empty() || sub.back() < envelope[1]) {
                sub.emplace_back(envelope[1]);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), envelope[1]);
                *it = envelope[1];
            }
        }

        return sub.size();

        return sub.size();
    }
};