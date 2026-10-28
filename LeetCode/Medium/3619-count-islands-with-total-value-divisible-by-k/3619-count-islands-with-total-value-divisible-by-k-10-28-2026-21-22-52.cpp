class Solution {
public:
    long long find(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r,
             int c, int m, int n) {
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        if (r >= m || c >= n || r < 0 || c < 0)
            return 0LL;
        if (grid[r][c] == 0 || visited[r][c])
            return 0LL;
        long long sum = 0;
        sum += grid[r][c];
        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            sum += find(grid, visited, nr, nc, m, n);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    long long sum = find(grid, visited, i, j, m, n);
                    cnt += (sum % (1LL*k) == 0);
                }
            }
        }
        return cnt;
    }
};