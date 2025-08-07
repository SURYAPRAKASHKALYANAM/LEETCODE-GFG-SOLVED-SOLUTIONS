class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = len - 1, mid;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            // cout<<mid<<" ";
            if ((mid - 1 >= 0 && nums[mid - 1] == nums[mid])) {
                if ((mid - start + 1) % 2 == 0)
                    start = mid + 1;
                else
                    end = mid - 2;
            } else if ((mid + 1 < len && nums[mid] == nums[mid + 1])) {
                if ((end - mid + 1) % 2 == 0)
                    end = mid - 1;
                else
                    start = mid + 2;
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
};