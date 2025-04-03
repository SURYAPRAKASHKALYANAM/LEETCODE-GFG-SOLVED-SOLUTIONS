class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(), maxright;
        vector<int> maxleft(n, 0);
        maxleft[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxleft[i] = max(maxleft[i + 1], nums[i]);
        }
        maxright = nums[0];
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, (long long)(maxright - nums[i]) * maxleft[i + 1]);
            maxright = max(maxright, nums[i]);
        }
        return ans;
    }
};