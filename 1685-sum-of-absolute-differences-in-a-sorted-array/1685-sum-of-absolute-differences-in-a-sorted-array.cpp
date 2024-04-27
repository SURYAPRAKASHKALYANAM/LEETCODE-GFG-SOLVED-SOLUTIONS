class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        vector<int> pre(nums.size(),0),post(nums.size(),0),ans(nums.size());
        pre[0]=nums[0];
        post[nums.size()-1]=nums.back();
        for(int i=1;i<nums.size();i++) pre[i]=pre[i-1]+nums[i];
        for(int i=nums.size()-2;i>=0;i--) post[i]=post[i+1]+nums[i];
        ans[0]=post[0]-(nums.size()*nums[0]);
        for(int i=1;i<nums.size()-1;i++)
        {
            int before=i+1,after=nums.size()-before;
            ans[i]=(before*nums[i]-pre[i])+(post[i+1]-after*nums[i]);
        }
        ans[nums.size()-1]=(nums.size()*nums[nums.size()-1])-pre[nums.size()-1];
        return ans;
    }
};