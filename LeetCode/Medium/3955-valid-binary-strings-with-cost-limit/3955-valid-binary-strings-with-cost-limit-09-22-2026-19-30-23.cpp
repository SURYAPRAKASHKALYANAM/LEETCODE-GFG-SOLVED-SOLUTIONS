class Solution {
public:
    void find(string s, vector<string>& ans, int len, int cur, int k) {
        if (s.size() == len) {
            if (cur <= k)
                ans.emplace_back(s);
            return;
        }
        if (s.back() == '1') {
            find(s + "0", ans, len, cur, k);
        } else {
            find(s + "1", ans, len, cur + s.size(), k);
            find(s + "0", ans, len, cur, k);
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        find("1", ans, n, 0, k);
        find("0", ans, n, 0, k);
        return ans;
    }
};