class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int mid = (len / 2);
        long long ans = 0LL;
        if (nums[mid] > k) {
            while (mid >= 0 && nums[mid] > k)
                ans += (nums[mid--] - k);
        } else if (nums[mid] < k) {
            while (mid < len && nums[mid] < k)
                ans += (k - nums[mid++]);
        }
        return ans;
    }
};