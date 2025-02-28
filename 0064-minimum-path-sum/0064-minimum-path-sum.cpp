class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // top
                int top = i - 1;
                if (top >= 0) {
                    dp[i][j] = grid[i][j] + dp[top][j];
                }
                // right
                int left = j - 1;
                if (left >= 0) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][left]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};