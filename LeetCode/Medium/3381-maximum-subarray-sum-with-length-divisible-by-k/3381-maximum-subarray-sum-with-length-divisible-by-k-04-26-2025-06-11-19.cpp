class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> minsum;
        long long sum = 0, max_sum = LONG_MIN;
        minsum[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum += nums[i - 1];
            if (minsum.find(i % k) != minsum.end()) {
                max_sum = max(sum - minsum[i % k], max_sum);
                minsum[i % k] = min(sum, minsum[i % k]);
            } else
                minsum[i % k] = sum;
        }
        return max_sum;
    }
};