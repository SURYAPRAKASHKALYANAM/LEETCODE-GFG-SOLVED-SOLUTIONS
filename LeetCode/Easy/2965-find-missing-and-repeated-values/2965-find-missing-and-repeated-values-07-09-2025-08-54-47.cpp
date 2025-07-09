class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long n = grid.size(), _n = n * n;
        long tot_sum = 0, a, sq_sum = 0, actual_sum = _n * (_n + 1) / 2;
        long aactual_sq_sum = (_n * (_n + 1) * (2 * _n + 1)) / 6;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tot_sum += grid[i][j];
                sq_sum += grid[i][j] * grid[i][j];
            }
        }
        // X-Y == S - SN
        int val1 = tot_sum - actual_sum;
        // X2-Y2 = S2 - S2N
        // (X-Y) * (X+Y) = S2-S2N
        // (X+Y) = (S2-SN) / val1;
        int val2 = (sq_sum - aactual_sq_sum) / val1;
        int X = (val1 + val2) / 2;
        int Y = val2 - X;
        return {X, Y};
    }
};