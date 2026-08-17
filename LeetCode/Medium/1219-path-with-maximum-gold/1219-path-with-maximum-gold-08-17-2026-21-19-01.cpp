class Solution {
public:
    void find(int r , int c,int sum,int &max_sum,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        visited[r][c]=1;
        sum+=grid[r][c];
        max_sum=max(max_sum,sum);
        int delrow[]={-1,0,+1,0},delcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
            int row=r+delrow[i],col=c+delcol[i];
            if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && visited[row][col]==0 && grid[row][col]!=0)
            {
                find(row,col,sum,max_sum,grid,visited);
            }
        }
        visited[r][c]=0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int sum=0,max_sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    vector<vector<int>> visited(m,vector<int> (n,0));
                    find(i,j,sum,max_sum,grid,visited);
                    // visited.clear();
                }
            }
        }
        return max_sum;
    }
};