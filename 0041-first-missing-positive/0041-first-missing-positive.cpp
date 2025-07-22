class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] < 1 || nums[i] > len)
                nums[i] = 0;
        }
        // [-3,9,16,4,5,16,-4,9,26,2,1,19,-1,25,7,22,2,-7,14,2,5,-6,1,17,3,24,-4,17,15]
        // [0,9,16,4,5,16,0,9,26,2,1,19,0,25,7,22,2,0,14,2,5,0,1,17,3,24,0,17,15]
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0 || nums[i] == i + 1)
                continue;
            int mod = nums[i] % len;
            if (mod == 0)
                mod = len;
            if (nums[mod - 1] == 0)
                swap(nums[i], nums[mod - 1]);
            else {
                if (nums[i] != nums[mod - 1]) {
                    swap(nums[i], nums[mod - 1]);
                    i--;
                } else {
                    nums[i] = 0;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return len + 1;
    }
};