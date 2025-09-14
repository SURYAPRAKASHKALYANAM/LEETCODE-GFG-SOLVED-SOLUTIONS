class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int l = 0, r = 0, len = s.size();
        int cnt = 0;
        while (r < len) {
            while (r < len && s[l] == s[r])
                r++;
            long long n = (r - l);
            l = r;
            cnt = (cnt + (n * (n + 1) / 2)) % mod;
        }
        return cnt;
    }
};