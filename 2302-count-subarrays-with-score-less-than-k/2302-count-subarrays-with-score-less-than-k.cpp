class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt = 0, sum = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += (nums[r] * 1LL);
            while (((long long)sum * (long long)(r - l + 1)) > (long long)(k - 1)) {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};