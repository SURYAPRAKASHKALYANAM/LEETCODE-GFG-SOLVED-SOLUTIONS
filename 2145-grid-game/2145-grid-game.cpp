class Solution
{
    public:
        long long gridGame(vector<vector < int>> &grid)
        {
            int n = grid[0].size();
            if (n == 1)
                return 0;
            vector<vector < long double>> suffix(2, vector < long double > (n));
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < n; j++) suffix[i][j] = grid[i][j];
            }
            for (int i = n - 2; i >= 0; i--)
            {
                suffix[0][(n - 1) - i] += suffix[0][(n - 2) - i];
                suffix[1][i] += suffix[1][i + 1];
            }
            long long min_ans = LONG_MAX;
            for (int i = 0; i < n; i++)
            {
                long long maxi = 0;
                if (suffix[0][n - 1] - suffix[0][i] > suffix[1][0] - suffix[1][i])
                    maxi = suffix[0][n - 1] - suffix[0][i];
                else maxi = suffix[1][0] - suffix[1][i];
                min_ans = min(min_ans, maxi);
            }
            return min_ans;
        }
};