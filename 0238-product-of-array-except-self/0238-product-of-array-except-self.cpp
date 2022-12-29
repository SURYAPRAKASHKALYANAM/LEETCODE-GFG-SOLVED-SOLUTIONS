class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
       vector<int> ans(nums.size(),0);
        long long mul=1,z=0;
        for(auto i:nums)
        {
            if(i!=0) mul*=i;
            else z++;
        }
        if(z>1) return ans;
        else
        {
            if(z==1)
            {
                for(auto i=0;i<nums.size();i++)
                    if(nums[i]==0) ans[i]=mul;
                return ans;
            }
            for(auto i=0;i<nums.size();i++)
            {
                if(nums[i]==0) ans[i]=mul;
                else ans[i]=mul/nums[i];
            }
        }
        return ans;
        
    }
};