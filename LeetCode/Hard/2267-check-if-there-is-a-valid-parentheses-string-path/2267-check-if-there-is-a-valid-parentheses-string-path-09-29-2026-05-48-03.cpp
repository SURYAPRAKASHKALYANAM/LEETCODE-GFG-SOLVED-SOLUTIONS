class Solution {
public:
    int dp[100][100][205] = {};
    bool dfs(int x, int y, int cnt, vector<vector<char>>& grid, int m, int n) {
        if (x >= m || x < 0 || y >= n || y < 0)
            return false;
        cnt += (grid[x][y] == '(' ? 1 : -1);
        if (x == m - 1 && y == n - 1)
            return cnt == 0;
        if (cnt < 0 || dp[x][y][cnt])
            return false;
        dp[x][y][cnt] = 1;
        return dfs(x + 1, y, cnt, grid, m, n) || dfs(x, y + 1, cnt, grid, m, n);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')')
            return false;
        return dfs(0, 0, 0, grid, m, n);
    }
};