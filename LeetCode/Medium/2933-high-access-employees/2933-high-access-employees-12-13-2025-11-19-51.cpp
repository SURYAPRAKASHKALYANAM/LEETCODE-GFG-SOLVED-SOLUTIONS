class Solution {
public:
    int hrmins = 3600;
    int convert(string& s) {
        return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 +
               ((s[2] - '0') * 10 + (s[3] - '0'));
    }
    vector<string>
    findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> times;
        vector<string> ans;
        sort(access_times.begin(), access_times.end(),
             [](auto p1, auto p2) { return p1[1] < p2[1]; });
        for (auto& access : access_times)
            times[access[0]].emplace_back(convert(access[1]));
        for (auto it : times) {
            for (int i = 2; i < it.second.size(); i++) {
                int afterhr = it.second[i - 2] + hrmins;
                if (it.second[i - 1] < afterhr && it.second[i] < afterhr) {
                    ans.emplace_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};