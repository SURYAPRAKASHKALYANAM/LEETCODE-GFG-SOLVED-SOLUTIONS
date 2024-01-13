class Solution {
public:
    int detect(int srow,int scol,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        int n=grid.size(),m=grid[0].size(),cnt=1;
        visited[srow][scol]=1;
        queue<pair<int,int>> q;
        q.push({srow,scol});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=r+delrow[i],col=c+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && grid[row][col]==1)
                {
                    cnt++;
                    visited[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),max_area=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int row =0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!visited[row][col] && grid[row][col]==1)
                {
                    max_area=max(max_area,detect(row,col,grid,visited));
                }
            }
        }
        return max_area;
    }
};