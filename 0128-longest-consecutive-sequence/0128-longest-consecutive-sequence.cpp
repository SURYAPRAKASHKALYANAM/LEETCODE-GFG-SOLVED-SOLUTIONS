class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int max_len = 1, end = 0, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[end] + 1 == nums[i]) {
                cnt++;
            } else {
                cnt = 1;
            }
            end = i;
            max_len = max(max_len, cnt);
        }
        return nums.size() ? max_len : 0;
    }
};