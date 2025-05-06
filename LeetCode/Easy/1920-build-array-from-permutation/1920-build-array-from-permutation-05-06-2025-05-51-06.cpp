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
        helper(nums, 0);
        return nums;
    }
};