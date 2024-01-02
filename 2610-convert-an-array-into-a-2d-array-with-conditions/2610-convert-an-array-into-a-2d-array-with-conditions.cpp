class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        map<int,int> m;
        for(auto i:nums) m[i]++;
        int k=nums.size();
        
        while(k)
        {
            vector<int> temp;
            for(auto i=m.begin();i!=m.end();i++)
            {
                if(i->second!=0)
                {
                    k--;
                    temp.emplace_back(i->first);
                    i->second--;
                }
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};