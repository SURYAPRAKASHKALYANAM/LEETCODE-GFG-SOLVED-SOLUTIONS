class Solution {
public:
    vector<int> find(int srow,int scol,vector<vector<int>>& land,vector<vector<int>> &visited)
    {
        int n=land.size(),m=land[0].size();
        visited[srow][scol]=1;
        queue<pair<int,int>> q;
        q.push({srow,scol});
        vector<int> ans={srow,scol,srow,scol};
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=r+delrow[i],col=c+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && land[row][col])
                {
                    visited[row][col]=1;
                    q.push({row,col});
                    ans[2]=max(ans[2],row);
                    ans[3]=max(ans[3],col);
                }
            }
        }
        return ans;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(land[row][col]==1 && !visited[row][col])
                {
                    ans.emplace_back(find(row,col,land,visited));
                }
            }
        }
        return ans;
    }
};