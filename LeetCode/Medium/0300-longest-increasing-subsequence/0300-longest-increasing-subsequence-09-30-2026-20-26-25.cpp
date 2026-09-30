class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // optimal
        // vector<int> sub;
        // for (int j = 0; j < nums.size(); j++) {
        //     if (sub.empty() || sub.back() < nums[j]) {
        //         sub.push_back(nums[j]);
        //     } else {
        //         auto it = lower_bound(sub.begin(), sub.end(),
        //                               nums[j]);  // ele>=nums[j]
        //         *it = nums[j];
        //     }
        // }
        // return sub.size();

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