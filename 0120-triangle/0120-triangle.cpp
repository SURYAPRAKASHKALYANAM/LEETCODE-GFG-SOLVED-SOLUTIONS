class Solution {
public:
    int getIdx(int r, int c) { return (r * (r + 1)) / 2 + c; }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if (rows == 1)
            return triangle[0][0];
        int len = (rows * (rows + 1)) / 2;
        vector<int> dp(len, INT_MAX);
        dp[0] = triangle[0][0];
        int ans = INT_MAX;
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j <= i; j++) {
                int Idx = getIdx(i, j);
                if (j < i) {
                    dp[Idx] =
                        min(dp[Idx], dp[getIdx(i - 1, j)] + triangle[i][j]);
                }
                if (j - 1 >= 0) {
                    dp[Idx] =
                        min(dp[getIdx(i - 1, j - 1)] + triangle[i][j], dp[Idx]);
                }
                if (i == rows - 1) {
                    ans = min(ans, dp[Idx]);
                }
            }
        }
        return ans;
    }
};