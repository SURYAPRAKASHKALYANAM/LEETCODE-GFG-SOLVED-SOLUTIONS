class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i== n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }
        int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=r+delrow[i],col=c+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && !visited[row][col])
                {
                    visited[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] && !visited[i][j]) cnt++;
            }
        }
        return cnt;
    }
};