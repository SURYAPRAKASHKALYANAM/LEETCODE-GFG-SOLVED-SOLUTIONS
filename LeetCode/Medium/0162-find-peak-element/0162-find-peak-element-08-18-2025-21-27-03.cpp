class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[len - 1] > nums[len - 2])
            return len - 1;
        int start = 1, end = len - 2, mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid - 1] < nums[mid])
                start = mid + 1;
            else if (nums[mid] > nums[mid + 1])
                end = mid - 1;
            else
                start = mid+1;
        }
        return -1;
    }
};