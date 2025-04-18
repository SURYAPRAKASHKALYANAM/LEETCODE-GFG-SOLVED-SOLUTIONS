class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP ALGO O(N)
        int needlelen = needle.size();
        vector<int> lps(needlelen);
        lps[0] = 0;
        int l = 0, i = 1;
        while (i < needlelen) {
            if (needle[i] == needle[l]) {
                lps[i] = ++l;
                i += 1;
            } else {
                if (l != 0) {
                    l = lps[l - 1];
                } else
                    i++;
            }
        }
        l = 0, i = 0;
        while (i < haystack.size()) {
            if (needle[l] == haystack[i]) {
                i++;
                l++;
            } else {
                if (l != 0) {
                    l = lps[l - 1];
                } else
                    i++;
            }
            if (l == needlelen)
                return i - needlelen;
        }
        return -1;
    }
};