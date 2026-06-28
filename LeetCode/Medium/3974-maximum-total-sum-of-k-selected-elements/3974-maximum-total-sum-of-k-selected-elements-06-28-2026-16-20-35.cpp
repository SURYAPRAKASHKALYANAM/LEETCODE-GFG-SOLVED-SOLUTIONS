class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0LL;
        sort(nums.begin(), nums.end());
        int len = nums.size() - 1;
        while (k--) {
            if (mul) {
                ans += (nums[len] * 1LL * mul);
                mul--;
            } else {
                ans += nums[len];
            }
            len--;
        }
        return ans;
    }
};