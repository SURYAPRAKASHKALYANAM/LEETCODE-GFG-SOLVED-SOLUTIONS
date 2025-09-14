class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int len = nums.size();
        int cnt = 0, ans = 0;
        int l = 0;
        for (int i = 0; i < len; i++) {
            cnt += nums[i];
            while (cnt > goal) {
                cnt -= nums[l];
                l++;
            }
            ans += (i - l + 1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};