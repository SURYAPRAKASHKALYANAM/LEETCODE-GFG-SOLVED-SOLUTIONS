class Solution {
public:
    void helper(vector<int>& nums, int start) {
        if (start < nums.size()) {
            int idx = nums[start];
            int ele = nums[idx];
            helper(nums, start + 1);
            nums[start] = ele;
        }
    }
    vector<int> buildArray(vector<int>& nums) {
        // helper(nums, 0); without stack space
        for (int i = 0; i < nums.size(); i++) {
            nums[i] |= nums[nums[i] & 0xFFFF] << 16;
        }
        for (int& num : nums)
            num >>= 16;
        return nums;
    }
};