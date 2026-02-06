class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int start = 0, end = 0, maxi = 0;
        while (start < len) {
            while (end < len &&
                   (long long)nums[end] <= (long long)(k * (1LL) * nums[start]))
                end++;
            maxi = max(maxi, end - start);
            start++;
        }
        return len - maxi;
    }
};