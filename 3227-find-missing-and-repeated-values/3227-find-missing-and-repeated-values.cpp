class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), _n = n * n;
        vector<int> seen(_n + 1);
        int tot_sum = 0, a, actual_sum = _n * (_n + 1) / 2, curr = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tot_sum += grid[i][j];
                if (seen[grid[i][j]])
                    a = grid[i][j];
                seen[grid[i][j]] = 1;
            }
        }
        return {a, actual_sum - tot_sum + a};
    }
};