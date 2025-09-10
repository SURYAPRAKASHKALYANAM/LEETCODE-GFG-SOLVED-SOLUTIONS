class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l = 0, r = 0, cnt = 0;
        while (r < n) {
            if (nums[r] == 0)
                cnt++;
            while (l <= r && cnt > k) {
                cnt -= (nums[l] == 0);
                l++;
            }
            maxLen = max(r - l + 1, maxLen);
            r++;
        }
        return maxLen;
    }
};