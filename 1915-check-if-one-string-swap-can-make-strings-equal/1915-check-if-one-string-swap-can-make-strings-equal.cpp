class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), cnt = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) cnt++;
            counts[s1[i] - 'a']++, counts[s2[i] - 'a']--;
        }
        return (cnt == 0 || cnt == 2) &&
               count(counts.begin(), counts.end(), 0) == 26;
    }
};