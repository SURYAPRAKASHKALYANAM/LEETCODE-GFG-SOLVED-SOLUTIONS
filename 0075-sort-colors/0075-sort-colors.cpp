class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int left = -1, curr = 0, right = len;
        while (curr < right) {
            if (nums[curr] == 0) {
                left++;
                swap(nums[left], nums[curr]);
                curr++;
            } else if (nums[curr] == 2) {
                right--;
                swap(nums[right], nums[curr]);
            } else
                curr++;
        }
    }
};