class Solution {
public:
    bool allSame(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] & 1) != (nums[i - 1] & 1))
                return false;
        }
        return true;
    }
    bool isPoss(vector<int>& nums, int parity, int mini) {
        for (int i : nums) {
            if ((i & 1) == parity)
                continue;
            if (i - mini < 1) {
                return false;
            }
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        if (allSame(nums1))
            return true;
        int len = nums1.size();
        int emin = INT_MAX, omin = INT_MAX;
        for (int& i : nums1) {
            if (i & 1) {
                omin = min(omin, i);
            } else
                emin = min(emin, i);
        }
        return isPoss(nums1, 0, omin) || isPoss(nums1, 1, omin);
    }
};