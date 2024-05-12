class Solution
{
    public:
        vector<vector < int>> largestLocal(vector<vector < int>> &grid)
        {
            int n = grid.size();
            vector<vector < int>> ans(n - 2, vector<int> (n - 2, 0));
            for (int i = 1; i < n - 1; i++)
            {
                for (int j = 1; j < n - 1; j++)
                {
                    for (int ii = -1; ii <= 1; ii++)
                    {
                        for (int jj = -1; jj <= 1; jj++)
                        {
                            ans[i - 1][j - 1] = max(grid[i + ii][j + jj], ans[i - 1][j - 1]);
                        }
                    }
                }
            }
            return ans;
        }
};