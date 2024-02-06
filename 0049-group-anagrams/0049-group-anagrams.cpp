class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        map<string,vector<string>> m;
        for(auto i=0;i<strs.size();i++) 
        {
            auto k=strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].emplace_back(k);
        }
        
        for(auto i=m.begin();i!=m.end();i++) ans.emplace_back(i->second);
        return ans;
        
        
    }
};