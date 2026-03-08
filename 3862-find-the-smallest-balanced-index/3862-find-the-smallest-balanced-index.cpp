class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        const long long MAX_SUM = 1LL * 1e14;
        vector<long long> suff(n + 1, 1);
        for (int i = n - 1; i >= 0; --i) {
            if (suff[i + 1] > MAX_SUM) {
                suff[i] = MAX_SUM + 1;
            } else if (nums[i] > MAX_SUM / suff[i + 1]) {
                suff[i] = MAX_SUM + 1;
            } else {
                suff[i] = suff[i + 1] * nums[i];
            }
        }
        long long prefix_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (prefix_sum == suff[i + 1]) {
                return i;
            }
            prefix_sum += nums[i];
        }

        return -1;
    }
};