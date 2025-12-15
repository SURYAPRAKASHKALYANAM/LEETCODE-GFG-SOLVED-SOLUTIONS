class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int len = prices.size();
        vector<int> dp(len, 1);
        for (int i = 0; i < len; i++) {
            if (i - 1 >= 0 && prices[i - 1] == (prices[i] + 1))
                dp[i] = dp[i - 1] + 1;
            ans += (1LL * dp[i]);
        }
        return ans;
    }
};