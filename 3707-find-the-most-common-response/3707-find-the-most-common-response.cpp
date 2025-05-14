class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();
        int max_cnt = 0;
        unordered_map<string, int> counts;
        string ans = "";
        for (int i = 0; i < n; i++) {
            unordered_map<string, bool> seen;
            for (auto i : responses[i]) {
                if (!seen[i]) {
                    counts[i]++;
                    if (counts[i] >= max_cnt) {
                        if (counts[i] == max_cnt) {
                            ans = min(ans, i);
                        } else
                            ans = i;
                        max_cnt=counts[i];
                    }
                    seen[i] = true;
                }
            }
        }
        return ans;
    }
};