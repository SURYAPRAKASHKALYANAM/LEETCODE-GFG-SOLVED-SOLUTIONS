class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        vector<int> seen(256, -1);
        int l = 0, r = 0, max_len = 0;
        while (r < len) {
            if (seen[s[r]] != -1) {
                l = max(seen[s[r]] + 1, l);
            }
            max_len = max(max_len, r - l + 1);
            seen[s[r]] = r;
            r++;
        }
        return max_len;
    }
};