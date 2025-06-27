class Solution {
public:
    void find(int ind,vector<int>& nums,vector<vector<int>> &ans)
{
    if(ind==nums.size())
    {
        ans.emplace_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[i],nums[ind]);
        find(ind+1,nums,ans);
        swap(nums[i],nums[ind]);
    }
}
    vector<vector<int>> permute(vector<int>& nums)
     {
        vector<vector<int>>  ans;
        find(0,nums,ans);
        return ans;      
    }
};