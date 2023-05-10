class Solution {
public:
    void add(vector<int>&ans,int rs,int re,int cs,int ce,vector<vector<int>>& m)
    {
        for(int i=cs;i<=ce;i++) ans.emplace_back(m[rs][i]);
        for(int i=rs+1;i<=re;i++) ans.emplace_back(m[i][ce]);
        for(int i=ce-1;i>cs && rs!=re;i--) ans.emplace_back(m[re][i]);
        for(int i=re;i>rs&& ce!=cs;i--) ans.emplace_back(m[i][cs]);
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int row_start=0,row_end=matrix.size()-1,col_start=0,col_end=matrix[0].size()-1;
        while(row_start<=row_end && col_start<=col_end)
        {
            add(ans,row_start,row_end,col_start,col_end,matrix);
            row_start++;
            row_end--;
            col_start++;
            col_end--;
        }
        return ans;
    }
};