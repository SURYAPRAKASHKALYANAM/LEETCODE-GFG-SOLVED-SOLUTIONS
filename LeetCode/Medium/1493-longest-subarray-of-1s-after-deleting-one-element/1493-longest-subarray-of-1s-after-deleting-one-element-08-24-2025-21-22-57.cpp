class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr = 0, pre = 0;
        int max_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                max_sum = max(max_sum, pre + curr);
                pre = curr;
                curr = 0;
            } else
                curr++;
        }
        if (max_sum == 0 && curr != 0)
            return curr - 1;
        return max(max_sum, curr + pre);
    }
};