class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = len - 1, mid;
        int minEle = 1e4;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                minEle = min(minEle, nums[mid]);
                start++;
                end--;
                continue;
            }
            if (nums[mid] <= nums[end]) {
                minEle = min(minEle, nums[mid]);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return minEle;
    }
};