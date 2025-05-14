class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();
        map<string, int> counts;
        for (int i = 0; i < n; i++) {
            unordered_map<string, bool> seen;
            for (auto i : responses[i]) {
                if (!seen[i]) {
                    counts[i]++;
                    seen[i] = true;
                }
            }
        }
        string ans = "";
        int max_cnt = 0;
        for (auto i : counts) {
            if (i.second > max_cnt) {
                ans = i.first;
                max_cnt = i.second;
            }
        }
        return ans;
    }
};