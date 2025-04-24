class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(257, 0);
        int start = 0, end = 0, n = s.size();
        ;
        int curr = 0, max_len = 0;
        while (end < n) {
            while (end < n && !seen[s[end]]) {
                seen[s[end]]++;
                end++;
            }
            max_len = max(max_len, end - start);
            while (start < end) {
                seen[s[start]]--;
                start++;
                if (s[end] == s[start - 1]) {
                    break;
                }
            }
        }
        return max_len;
    }
};