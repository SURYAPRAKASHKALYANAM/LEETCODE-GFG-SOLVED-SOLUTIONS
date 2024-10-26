class Solution
{
    public:
        vector<vector < int>> onesMinusZeros(vector<vector < int>> &grid)
        {
            int r = grid.size(), c = grid[0].size();
            vector<vector < int>> ans(r, vector<int> (c, 0));
            vector<int> rone(r, 0), cone(c, 0);
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (grid[i][j]) rone[i]++, cone[j]++;
                }
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++) ans[i][j] = (2 *rone[i] - r) + (2 *cone[j] - c);
            }
            return ans;
        }
};