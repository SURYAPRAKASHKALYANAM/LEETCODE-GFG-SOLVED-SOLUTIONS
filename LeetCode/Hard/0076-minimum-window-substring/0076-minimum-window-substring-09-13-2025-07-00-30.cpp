class Solution {
public:
    string minWindow(string s, string t) {
        int min_wind = INT_MAX, sIndx = -1;
        int hash[123] = {0};
        for (auto i : t)
            hash[i]++;
        int count = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;
            while (count == t.size()) {
                if ((r - l + 1) < min_wind) {
                    min_wind = (r - l + 1);
                    sIndx = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }
        return sIndx >= 0 ? s.substr(sIndx, min_wind) : "";
    }
};