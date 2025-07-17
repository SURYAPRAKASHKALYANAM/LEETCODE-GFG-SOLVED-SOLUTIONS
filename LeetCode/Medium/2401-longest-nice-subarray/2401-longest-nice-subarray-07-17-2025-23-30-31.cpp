class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int cnt = 1, max_cnt = 1;
        int Orval = nums[0];
        int start = 0, end = 1, n = nums.size();
        while (start <= end && end < n) {
            if ((nums[end] & Orval) == 0) {
                max_cnt = max(max_cnt, end - start + 1);
            } else {
                while (start < n && (Orval & nums[end]) != 0)
                    Orval ^= nums[start++];
            }
            Orval |= nums[end++];
        }
        return max_cnt;
    }
};