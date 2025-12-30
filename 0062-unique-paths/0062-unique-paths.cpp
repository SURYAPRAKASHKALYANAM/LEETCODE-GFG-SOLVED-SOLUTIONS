class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& dp) {
        if (m < 0 || n < 0)
            return 0;
        if (m == 0 && n == 0)
            return 1;
        if (dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    }
    int uniquePaths(int m, int n) {
        //  use combinatrics
        // double res = 1;
        // int d = m + n - 2;
        // int r = m - 1;
        // for (int i = 1; i <= r; i++)
        // {
        //     res = res *(d - r + i) / i;
        // }
        // return (int) res;
        // dp
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);
    }
};