class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnts;
        for (auto i : t)
            cnts[i]++;
        int tLen = t.size(), sLen = s.size();
        int cnt = 0, min_window = INT_MAX;
        int sIdx = -1;
        int l = 0, r = 0;
        while (r < sLen) {
            if (cnts[s[r]] > 0) {
                cnt++;
            }
            cnts[s[r]]--;
            while (cnt == tLen) {
                int len = (r - l + 1);
                if (len < min_window) {
                    min_window = len;
                    sIdx = l;
                }
                cnts[s[l]]++;
                if (cnts[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        return sIdx == -1 ? "" : s.substr(sIdx, min_window);
    }
};