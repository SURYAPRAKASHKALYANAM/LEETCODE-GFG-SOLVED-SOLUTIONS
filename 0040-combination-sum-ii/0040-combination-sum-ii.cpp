class Solution {
public:
    void find(int ind,int target,vector<int>& candidates,vector<int> sub,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.emplace_back(sub);
            return;
        }
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i-1]==candidates[i]) continue;
            if(candidates[i]>target) break;
            sub.emplace_back(candidates[i]);
            find(i+1,target-candidates[i],candidates,sub,ans);
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
            vector<vector<int>> ans;
            vector<int> sub;
            sort(candidates.begin(),candidates.end());
            find(0,target,candidates,sub,ans);
            return ans;
    }
};