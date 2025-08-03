class Solution {
public:
    size_t array_hash(vector<int>& arr) {
        size_t hashVal = 0;
        const size_t multiplier = 31;

        for (int x : arr) {
            hashVal = hashVal * multiplier + hash<int>{}(x);
        }

        return hashVal;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<size_t, vector<string>> m;
        for (auto i = 0; i < strs.size(); i++) {
            vector<int> charfreq(26, 0);
            for (auto i : strs[i])
                charfreq[i - 'a']++;
            m[array_hash(charfreq)].emplace_back(strs[i]);
        }

        for (auto i = m.begin(); i != m.end(); i++)
            ans.emplace_back(i->second);
        return ans;
    }
};