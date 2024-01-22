class Solution
{
    public:
        int orangesRotting(vector<vector < int>> &grid)
        {
            int fresh = 0, cnt = 0;
            int n = grid.size(), m = grid[0].size();
            vector<vector < int>> visited(n, vector<int> (m, 0));
            queue<pair<pair<int, int>, int>> q;
            for (int row = 0; row < n; row++)
            {
                for (int col = 0; col < m; col++)
                {
                    if (grid[row][col] == 2)
                    {
                        q.push({{row,col},0});
                        visited[row][col]=2;
                    }
                    else if(grid[row][col]==1) fresh++;
                }
            }
            int tm=0;
            int delrow[]={-1,0,+1,0};
            int delcol[]={0,+1,0,-1};
            while(!q.empty())
            {
                int r=q.front().first.first;
                int c=q.front().first.second;
                int t=q.front().second;
                tm=max(t,tm);
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nrow=r+delrow[i];
                    int ncol=c+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                    {
                        if(grid[nrow][ncol]==1 && visited[nrow][ncol]!=2)
                        {
                            visited[nrow][ncol]=2;
                            q.push({{nrow,ncol},t+1});
                            cnt++;
                        }
                    }
                }
            }
            return (cnt==fresh)? tm:-1;
        }
};