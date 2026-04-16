class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size(), maxIS = 1;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxIS = max(maxIS, dp[i]);
        }
        return maxIS;
    }
};