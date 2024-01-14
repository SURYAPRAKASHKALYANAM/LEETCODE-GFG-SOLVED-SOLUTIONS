class Solution {
public:
    int find(int srow,int scol,vector<vector<int>> &grid,vector<vector<int>>& visited)
    {
        int n=grid.size(),m=grid[0].size();
        visited[srow][scol]=1;
        int cnt=grid[srow][scol];
        queue<pair<int,int>> q;
        q.push({srow,scol});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=r+delrow[i],col=c+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && grid[row][col]>0)
                {
                    visited[row][col]=1;
                    q.push({row,col});
                    cnt+=grid[row][col];
                }
            }  
        }
        return cnt;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int max_fish=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]>0 && !visited[row][col])
                {
                    max_fish=max(max_fish,find(row,col,grid,visited));
                }
            }
        }
        return max_fish;
    }
};