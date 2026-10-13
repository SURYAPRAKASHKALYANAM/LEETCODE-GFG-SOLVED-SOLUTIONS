class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& i : nums)
            i = abs(i);
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        long long ans = 0LL;
        while (l <= r) {
            ans += (1LL * nums[r] * nums[r]);
            if (l == r)
                break;
            ans -= (1LL * nums[l] * nums[l]);
            l++;
            r--;
        }
        return ans;
    }
};