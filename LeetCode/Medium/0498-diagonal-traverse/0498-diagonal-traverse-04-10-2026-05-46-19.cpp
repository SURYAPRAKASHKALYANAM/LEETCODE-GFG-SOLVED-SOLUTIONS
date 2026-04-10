class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        vector<int> ans;
        map<int,vector<int>> m;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++) m[i+j].emplace_back(mat[i][j]);
        }
        bool r=true;
        for(auto i:m)
        {
            if(r)
            {
                for(auto j=i.second.rbegin();j!=i.second.rend();j++) ans.emplace_back(*j);
            }
            else
            {
                for(auto j:i.second) ans.emplace_back(j);
            }
            r=!r;
        }
        return ans;
    }
};  