class Solution {
public:
    int max_substr = 0, len, K;
    void helper(string& s, char c) {
        int start = 0, end = 0, curr = 0;
        while (end < len) {
            while (curr <= K && end < len) {
                if (s[end] != c) {
                    curr++;
                }
                end++;
            }
            max_substr = max(max_substr, end - start - (curr > K));
            while (curr > K && end >= start) {
                if (s[start] != c) {
                    curr--;
                }
                start++;
            }
        }
    }
    int characterReplacement(string s, int k) {
        len = s.size();
        K = k;
        for (char c = 'A'; c <= 'Z'; c++) {
            helper(s, c);
        }
        return max_substr;
    }
};