class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long int c=0,zf=0;
        for(auto i=0;i<nums.size();i++)
        {
            if(nums[i]==0) c++;
            if(nums[i]!=0 || i==nums.size()-1)
            {
                zf+=(c*(c+1)/2);
                c=0;
            }
        }
        return zf;
    }
};