class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> counts;
        for (int i = 0; i < s.size(); i++) {
            counts[s[i]]--;
            counts[t[i]]++;
        }
        for (auto i : counts) {
            if (i.second != 0)
                return false;
        }
        return true;
    }
};