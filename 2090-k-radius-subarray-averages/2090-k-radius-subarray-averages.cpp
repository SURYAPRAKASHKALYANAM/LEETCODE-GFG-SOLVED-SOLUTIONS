class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        vector<int> ans(nums.size(),-1);
        long long sum=0;
        if(!k) return nums;
        if(2*k>=nums.size()) return ans;
        for(int i=0;i<=2*k && i<nums.size();i++) sum+=nums[i];
        for(int i=k;i+k<nums.size();i++)
        {
            ans[i]=sum/((2*k)+1);
            sum-=nums[i-k];
            if(i+k+1<nums.size()) sum+=nums[i+k+1];
        }
        return ans;
        
    }
};