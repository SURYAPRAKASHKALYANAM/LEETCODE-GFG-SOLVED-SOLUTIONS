class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int left=i+1,right=nums.size()-1;
            int start=nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(left<right)
            {
                if((nums[left]+nums[right]+start)==0)
                {
                    vector<int> temp={start,nums[left],nums[right]};
                    sol.emplace_back(temp);
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
                else if(nums[left]+nums[right]+start<0) left++;
                else right--;
            }
        }
        return sol;
        
    }
};