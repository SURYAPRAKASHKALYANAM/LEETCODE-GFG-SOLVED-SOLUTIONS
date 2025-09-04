class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_step = 0;
        int i = 0, end = nums.size() - 1;
        while (i < end) {
            max_step = max(max_step, nums[i]);
            if (max_step) {
                max_step--;
                i++;
            } else
                return false;
        }
        return true;
    }
};