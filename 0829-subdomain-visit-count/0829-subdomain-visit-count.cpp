class Solution {
public:
    vector<string> split_parts(string s) {
        vector<string> splits;
        string sub = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '.') {
                splits.push_back(sub);
                sub = s[i] + sub;
            } else if (s[i] == ' ') {
                splits.push_back(sub);
                sub.clear();
                continue;
            } else {
                sub = s[i] + sub;
            }
        }
        splits.emplace_back(sub);
        return splits;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> counts;
        for (auto i : cpdomains) {
            auto it = split_parts(i);
            int count = stoi(it.back());
            for (int j = 0; j < it.size() - 1; j++)
                counts[it[j]] += count;
        }
        for (auto i : counts)
            ans.emplace_back(to_string(i.second) + " " + i.first);
        return ans;
    }
};