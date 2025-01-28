class Solution {
public:
    int max_fish = INT_MIN;
    void bfs(int currx, int curry, vector<vector<int>>& grid, int& curr_fish,
             vector<vector<int>>& visited, int m, int n) {
        if (visited[currx][curry])
            return;
        else {
            visited[currx][curry] = 1;
            curr_fish += grid[currx][curry];
            max_fish = max(max_fish, curr_fish);
            int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                int r = currx + dx[i], c = curry + dy[i];
                if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] &&
                    grid[r][c])
                    bfs(r, c, grid, curr_fish, visited, m, n);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    int fish = 0;
                    bfs(i, j, grid, fish, visited, m, n);
                }
            }
        }
        return max_fish == INT_MIN ? 0 : max_fish;
    }
};