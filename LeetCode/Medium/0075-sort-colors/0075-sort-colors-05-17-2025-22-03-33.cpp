class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() - 1;
        int end = n , start = 0, curr = 0;
        while (curr <= end) {
            if (nums[curr] == 2) {
                swap(nums[curr], nums[end]);
                end--;
            } else if (nums[curr] == 0) {
                swap(nums[curr], nums[start]);
                start++;
                curr++;
            } else {
                curr++;
            }
        }
    }
};