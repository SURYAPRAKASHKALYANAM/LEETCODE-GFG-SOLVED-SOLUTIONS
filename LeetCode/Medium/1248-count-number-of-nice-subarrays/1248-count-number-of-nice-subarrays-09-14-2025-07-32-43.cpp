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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        for (auto& i : nums)
            i = (i & 1);
        return helper(nums, k) - helper(nums, k - 1);
    }
};