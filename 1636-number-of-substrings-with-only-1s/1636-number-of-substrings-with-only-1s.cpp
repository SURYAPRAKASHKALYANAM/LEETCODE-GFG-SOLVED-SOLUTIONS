class Solution {

public:
    int numSub(string s) {
        int len = s.size();
        int mod = 1e9 + 7;
        int zeroIdx = -1;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0')
                zeroIdx = i;
            else {
                while (i < len && s[i] == '1')
                    i++;
                i--;
                long long n = i - zeroIdx;
                ans = (ans + ((n % mod) * (n + 1) % mod / 2)) % mod;
            }
        }
        return ans;
    }
};