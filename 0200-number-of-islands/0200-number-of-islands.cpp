class Solution
{
    public:
        void bfs(int row, int col, vector<vector < char>> &grid, vector< vector< int>> &visited)
        {
            visited[row][col] = 1;
            queue<pair<int, int>> q;
            int n = grid.size(), m = grid[0].size();
            q.push({ row,
                col });
            int delrow[] = { -1,
                0,
                +1,
                0
            };
            int delcol[] = { 0,
                +1,
                0,
                -1
            };
            while (!q.empty())
            {
                int nrow = q.front().first;
                int ncol = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int currow = nrow + delrow[i];
                    int currcol = ncol + delcol[i];
                    if (currow >= 0 && currow < n && currcol >= 0 && currcol < m &&
                        !visited[currow][currcol] && grid[currow][currcol] == '1')
                    {
                        visited[currow][currcol] = 1;
                        q.push({ currow,
                            currcol });
                    }
                }
            }
        }
    int numIslands(vector<vector < char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector < int>> visited(n, vector<int> (m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    visited[row][col] = 1;
                    bfs(row, col, grid, visited);
                }
            }
        }
        return cnt;
    }
};