class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        if(nums.size()==1) return 1;
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        int first=min(mini,maxi),last=max(mini,maxi);
        // cout<<nums[first]<<nums[last];
        int ans=min(first+(int)(nums.size()-last)+1,(int)min(last+1,(int)(nums.size()-first)));
        return (ans>=2)? ans:ans+1;
        
    }
};