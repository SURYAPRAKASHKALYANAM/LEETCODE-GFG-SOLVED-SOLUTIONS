class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        for(auto i=1;i<=nums.size();i++) m[i]=0;
        for(auto i:nums) m[i]++;
        vector<int> ans;
        for(auto i:m)
        {
            if(i.second>1) ans.insert(ans.begin(),i.first);
            if(i.second==0) ans.emplace_back(i.first);
        }
        return ans;
    }
};