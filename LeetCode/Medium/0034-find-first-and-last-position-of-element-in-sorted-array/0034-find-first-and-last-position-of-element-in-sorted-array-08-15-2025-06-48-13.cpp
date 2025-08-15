class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size(), first = -1, last = -1;
        int start = 0, end = len - 1, mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                first = mid;
            if (nums[mid] >= target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        if (first == -1)
            return {-1, -1};
        start = 0, end = len - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                last = mid;
            if (nums[mid] <= target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return {first, last};
    }
};