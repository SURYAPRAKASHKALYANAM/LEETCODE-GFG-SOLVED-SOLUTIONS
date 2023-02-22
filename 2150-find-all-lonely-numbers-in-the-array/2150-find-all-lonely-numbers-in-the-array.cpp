class Solution {
public:
    vector<int> findLonely(vector<int>& nums) 
    {
        map<int,int> m;
        vector<int> ans;
        for(auto i:nums) m[i]++;
        for(auto j:m)
        {  
            if(j.second==1 && m[(j.first)-1]==0 && m[(j.first)+1]==0) ans.emplace_back(j.first);
        }
        return ans;
    }
};