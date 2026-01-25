class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int len = nums.size();
        int end = len - 1;
        while (end > 0) {
            if (nums[end] <= nums[end - 1])
                break;
            end--;
        }
        return end;
    }
};