class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        set<string> unique(words2.begin(), words2.end());
        vector<int> max_freq(26, 0);
        for (auto word : unique) {
            vector<int> have(26, 0);
            for (char ch : word)
                have[ch - 'a']++;
            for (int i = 0; i < 26; i++) {
                max_freq[i] = max(max_freq[i], have[i]);
            }
        }
        for (auto word : words1) {
            vector<int> have(26, 0);
            for (auto ch : word)
                have[ch - 'a']++;
            bool add = 1;
            for (int i = 0; i < 26; i++) {
                if (max_freq[i] > have[i]) {
                    add = 0;
                    break;
                }
            }
            if (add)
                ans.emplace_back(word);
        }
        return ans;
    }
};