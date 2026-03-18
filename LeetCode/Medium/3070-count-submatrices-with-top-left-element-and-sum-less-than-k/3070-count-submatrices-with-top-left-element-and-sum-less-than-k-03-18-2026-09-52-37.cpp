class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0, prevSum;
        for (int i = 0; i < m; i++) {
            prevSum = 0;
            for (int j = 0; j < n; j++) {
                prevSum += grid[i][j];
                grid[i][j] = prevSum + ((i - 1 >= 0) ? grid[i - 1][j] : 0);
                if (grid[i][j] <= k)
                    cnt++;
            }
        }
        return cnt;
    }
};