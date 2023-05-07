class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int> teams,loose;
        for(auto i:matches)
        {
            teams[i[0]]++;
            teams[i[1]]++;
            loose[i[1]]++;
        }
        vector<int> notlost,exactlyone;
        for(auto it:teams)
        {
            if(!loose[it.first]) notlost.emplace_back(it.first);
            else if(loose[it.first]==1) exactlyone.emplace_back(it.first);
        }
        sort(notlost.begin(),notlost.end());
        sort(exactlyone.begin(),exactlyone.end());
        vector<vector<int>> ans;
        ans.emplace_back(notlost);
        ans.emplace_back(exactlyone);
        return ans;
        
        
    }
};