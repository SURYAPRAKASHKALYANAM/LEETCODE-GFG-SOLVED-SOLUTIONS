class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        map<char, int> m;
        m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;
        int n = words.size();
        vector<int> pref(n, 0), ans;
        pref[0] = m[words[0].front()] && m[words[0].back()];
        for (auto i = 1; i < words.size(); i++)
            pref[i] = (m[words[i].front()] && m[words[i].back()]) + pref[i - 1];
        for (auto q : queries) {
            int beg = q[0] - 1, end = q[1];
            if (beg < 0)
                ans.emplace_back(pref[end]);
            else if (end > n - 1)
                ans.emplace_back(pref[end - 1] - pref[beg]);
            else
                ans.emplace_back(pref[end] - pref[beg]);
        }
        return ans;
    }
};