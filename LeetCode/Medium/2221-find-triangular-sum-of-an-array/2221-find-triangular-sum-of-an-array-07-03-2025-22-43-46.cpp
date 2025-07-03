class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int i;
        while(nums.size()!=1)
        {
            for(i=0;i<nums.size()-1;i++)
            {
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};