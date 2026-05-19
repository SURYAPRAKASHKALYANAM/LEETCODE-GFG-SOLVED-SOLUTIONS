class Solution {
public:
    int find(int pos, vector<int>& nums, vector<int>& dp) {
        if (pos >= nums.size()) {
            return 0;
        }

        if (pos == nums.size() - 1)
            return 0;

        if (dp[pos] != INT_MAX)
            return dp[pos];
        int mini = INT_MAX;
        for (int nxt = pos + 1; nxt <= nums[pos] + pos; nxt++) {
            int ste = find(nxt, nums, dp);
            if (ste != -1)
                mini = min(mini, 1 + ste);
        }
        return dp[pos] = (mini == INT_MAX ? -1 : mini);
    }
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, INT_MAX);
        return find(0, nums, dp);
    }
};