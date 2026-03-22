class Solution {
public:
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
        int len = nums1.size();
        int omin = INT_MAX;
        for (int& i : nums1) {
            if (i & 1)
                omin = min(omin, i);
        }
        return isPoss(nums1, 0, omin) || isPoss(nums1, 1, omin);
    }
};