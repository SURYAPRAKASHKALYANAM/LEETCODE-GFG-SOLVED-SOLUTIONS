class Solution {
public:
    int findCnt(vector<int>& nums, int target, int len, vector<int>& dp) {
        if (target == 0)
            return 1;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if ((target - nums[i]) >= 0 && dp[target - nums[i]] == -1)
                dp[target - nums[i]] = findCnt(nums, target - nums[i], len, dp);
            if ((target - nums[i]) >= 0)
                cnt += dp[target - nums[i]];
        }
        return dp[target] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1001, -1);
        return findCnt(nums, target, nums.size(), dp);
    }
};