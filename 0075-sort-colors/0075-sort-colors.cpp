class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
    /* sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(nums[i]>nums[j])
                    swap(nums[i],nums[j]);
            }
        }*/
        for(int i=0,initial=0,end=nums.size()-1;i<=end;i++)
        {
            if(nums[i]==2) swap(nums[i--],nums[end--]);
            else if(nums[i]==0) swap(nums[i],nums[initial++]);
        }
        
        
    }
};