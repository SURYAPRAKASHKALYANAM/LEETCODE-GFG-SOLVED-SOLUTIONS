class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(1e5 + 1, 0);
        int mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            long long ans = 1;
            if (i - zero >= 0)
                ans += dp[i - zero];
            if (i - one >= 0)
                ans += dp[i - one];
            dp[i] = ans % mod;
        }
        return (dp[high] - dp[low - 1] + mod ) % mod;
    }
};