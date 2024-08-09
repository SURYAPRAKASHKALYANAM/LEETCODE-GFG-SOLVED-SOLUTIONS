class Solution
{
    public:
        bool sumcheck(int rstart, int cstart, vector<vector < int>> &grid)
        {
            int r1 = (grid[rstart][cstart] + grid[rstart][cstart + 1] + grid[rstart][cstart + 2]);
            int r2 = (grid[rstart + 1][cstart] + grid[rstart + 1][cstart + 1] + grid[rstart + 1][cstart + 2]);
            int r3 = (grid[rstart + 2][cstart] + grid[rstart + 2][cstart + 1] + grid[rstart + 2][cstart + 2]);
            int c1 = (grid[rstart][cstart] + grid[rstart + 1][cstart] + grid[rstart + 2][cstart]);
            int c2 = (grid[rstart][cstart + 1] + grid[rstart + 1][cstart + 1] + grid[rstart + 2][cstart + 1]);
            int c3 = (grid[rstart][cstart + 2] + grid[rstart + 1][cstart + 2] + grid[rstart + 2][cstart + 2]);
            int d1 = (grid[rstart][cstart] + grid[rstart + 1][cstart + 1] + grid[rstart + 2][cstart + 2]);
            int d2 = (grid[rstart + 2][cstart] + grid[rstart + 1][cstart + 1] + grid[rstart][cstart + 2]);
            return (r1 == r2) && (r2 == r3) && (c1 == c2) && (c2 == c3) && (d1 == d2) && (r1 == c1) && (d1 == c1);
        }
    bool check(int rstart, int cstart, vector<vector < int>> &grid)
    {
        unordered_map<int, int> m;
        int cnt = 0;
        for (int i = rstart; i < rstart + 3; i++)
        {
            for (int j = cstart; j < cstart + 3; j++)
            {
                if (i < grid.size() && j < grid[0].size())
                {
                    if (grid[i][j] > 0 && grid[i][j] <= 9 && m[grid[i][j]] == 0)
                    {
                        m[grid[i][j]]++;
                        cnt++;
                    }
                    else return false;
                }
                else return false;
            }
        }
        return cnt == 9;
    }
    int numMagicSquaresInside(vector<vector < int>> &grid)
    {
        int cnt = 0;
        for (int i = 1; i < grid.size() - 1; i++)
        {
            for (int j = 1; j < grid[0].size() - 1; j++)
            {
                if (check(i - 1, j - 1, grid))
                {
                    if (sumcheck(i - 1, j - 1, grid)) cnt++;
                }
            }
        }
        return cnt++;
    }
};