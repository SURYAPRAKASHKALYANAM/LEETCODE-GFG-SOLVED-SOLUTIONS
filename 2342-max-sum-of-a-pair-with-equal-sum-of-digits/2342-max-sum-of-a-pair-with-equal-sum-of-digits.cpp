class Solution {
public:
    int sum(int n)
    {
        if(n==0) return 0;
        return n%10+sum(n/10);
    }
    int maximumSum(vector<int>& nums) 
    {
        int maxi=-1;
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int ind=sum(nums[i]);
            if(m[ind])
            {
                maxi=max(maxi,m[ind]+nums[i]);
                m[ind]=max(m[ind],nums[i]);
            }
            else m[ind]=nums[i];
            
        }
        return maxi;
        
    }
};