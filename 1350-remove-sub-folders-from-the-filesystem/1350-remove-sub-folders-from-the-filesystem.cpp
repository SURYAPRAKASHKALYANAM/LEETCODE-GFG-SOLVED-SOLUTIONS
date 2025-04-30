class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(begin(folder), end(folder));
        ans.emplace_back(folder[0]);
        for (int i = 1; i < folder.size(); i++) {
            auto pos = folder[i].find(ans.back());
            if (pos == string::npos || pos != 0 || 
                ((ans.back().size() + pos) < folder[i].size() &&
                 folder[i][(ans.back().size() + pos)] != '/')) {
                ans.emplace_back(folder[i]);
            }
        }
        return ans;
    }
};