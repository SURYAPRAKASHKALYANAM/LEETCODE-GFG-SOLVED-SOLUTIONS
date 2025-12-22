class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int len = prices.size();
        // vector<int> dp(len, 1);
        int prev = 1;
        for (int i = 0; i < len; i++) {
            // dp[i] = dp[i - 1] + 1;
            if (i - 1 >= 0 && prices[i - 1] == (prices[i] + 1))
                prev++;
            else
                prev = 1;
            // ans += (1LL * dp[i]);
            ans += (1LL * prev);
        }
        return ans;
    }
};