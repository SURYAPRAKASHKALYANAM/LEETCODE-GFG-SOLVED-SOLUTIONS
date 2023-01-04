class Solution
{
    public:
        int findMin(vector<int> &nums)
        {
            if(nums.size()==2) return min(nums[0],nums[1]);
            if(nums[0]-nums.back() <0) return nums[0];
            int mid, low = 0, high = nums.size() - 1;
            while (low <= high)
            {
                if(high>0 && high <nums.size()-1)
                if (nums[high - 1] > nums[high] && nums[high] < nums[high + 1]) return nums[high];
                if(low>0 && low<nums.size()-1)
                if (nums[low - 1] > nums[low] && nums[low] < nums[low + 1]) return nums[low];
                mid = (low + high) / 2;
                if (mid == 0 || mid == nums.size() - 1) return nums[mid];
                if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) return nums[mid];
                else if (nums[low] - nums[mid] >= nums[mid] - nums[high]) high = mid-1;
                else low = mid+1;
            }
            return nums[mid];
        }
};