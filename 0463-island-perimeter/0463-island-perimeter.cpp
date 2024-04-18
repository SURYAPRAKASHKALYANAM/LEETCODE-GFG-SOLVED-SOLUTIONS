class Solution
{
    public:
        int islandPerimeter(vector<vector < int>> &grid)
        {
            int cnt = 0, n = grid.size(), m = grid[0].size(),
            delrow[]={-1,0,1,0},delcol[]={0,1,0,-1},default_edges = 0, col, row;
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < m; c++)
                {
                    if (grid[r][c])
                    {
                        default_edges = 4;
                        for (int i = 0; i < 4; i++)
                        {
                            row = r + delrow[i], col = c + delcol[i];
                            if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col]) default_edges--;
                        }
                        cnt += default_edges;
                    }
                }
            }
            return cnt;
        }
};