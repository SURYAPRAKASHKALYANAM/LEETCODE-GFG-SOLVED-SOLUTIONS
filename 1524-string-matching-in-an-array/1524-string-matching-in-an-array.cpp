class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (auto i = 0; i < words.size(); i++) {
            for (auto j : words) {
                if (j != words[i] && j.find(words[i]) != string::npos) {
                    ans.emplace_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};