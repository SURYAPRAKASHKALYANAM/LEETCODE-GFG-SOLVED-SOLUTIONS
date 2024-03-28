class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int max_len=0;
        int left=0,right=0;
        while(right<nums.size())
        {
            count[nums[right]]++;
            if(count[nums[right]]>k)
            {
                while(nums[left]!=nums[right])
                {
                    count[nums[left++]]--;
                }
                count[nums[left++]]--;
            }
            max_len=max(max_len,(right-left+1));
            right++;
        }
        return max_len;
        
    }
};