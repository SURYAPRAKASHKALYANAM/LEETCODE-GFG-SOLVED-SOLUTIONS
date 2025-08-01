class Solution {
public:
    void lpsHelper(vector<int>& lps, string s) {
        int i = 1, j = 0, len = s.size();
        while (i < len) {
            if (s[i] == s[j]) {
                lps[i] = j + 1;
                j++;
                i++;
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = lps[j - 1];
                }
                if (s[i] == s[j]) {
                    lps[i] = j + 1;
                    j++;
                }
                i++;
            }
        }
    }
    int strStr(string haystack, string needle) {
        string s = needle + "$" + haystack;
        int len = s.size() + haystack.size() + 1;
        vector<int> lps(len, 0);
        lpsHelper(lps, s);
        for (int i = needle.size() + 1; i < len; i++) {
            if (lps[i] == needle.size())
                return i - 2 * needle.size();
        }
        return -1;
    }
};