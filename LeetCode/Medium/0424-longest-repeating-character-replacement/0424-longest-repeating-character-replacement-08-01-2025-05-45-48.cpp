class Solution {
public:
    int max_wind = 0, n;
    void helper(string s, int k, char c) {
        int start = 0, end = 0, curr = 0;
        while (end < n) {
            while (curr <= k && end < n) {
                if (s[end] != c) {
                    curr++;
                }
                end++;
            }
            max_wind = max(max_wind, end - start - (curr > k));
            while (curr > k && start <= end) {
                if (s[start] != c)
                    curr--;
                start++;
            }
        }
    }
    int characterReplacement(string s, int k) {
        n = s.size();
        for (char c = 'A'; c <= 'Z'; c++) {
            helper(s, k, c);
        }
        return max_wind;
    }
};