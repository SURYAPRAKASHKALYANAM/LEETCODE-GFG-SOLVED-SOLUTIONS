class Solution {
public:
    void find(int ind,vector<int> &nums,vector<int> &sub,vector<vector<int>> &ans)
    {
        ans.emplace_back(sub);
        for(int i=ind;i<nums.size();i++)
        {
            sub.emplace_back(nums[i]);
            find(i+1,nums,sub,ans);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> sub;
        find(0,nums,sub,ans);
        return ans;
    }
};