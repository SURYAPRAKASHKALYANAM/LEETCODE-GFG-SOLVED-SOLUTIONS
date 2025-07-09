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

    // this is for arr-1d of 1-n
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        // find xor of ( 1 to len and arr[i])
        int len = nums.size();
        int xor_val = 0;
        for (int i = 0; i < len; i++) {
            xor_val ^= nums[i];
            xor_val ^= (i + 1);
        }
        int right_most = xor_val & ~(xor_val-1);
        int Zero_xor = 0, one_xor = 0;
        for (int i = 0; i < len; i++) {
            if ((i + 1) & right_most)
                one_xor ^= (i + 1);
            else
                Zero_xor ^= (i + 1);
            if (nums[i] & right_most)
                one_xor ^= nums[i];
            else
                Zero_xor ^= nums[i];
        }
        for (int i : nums) {
            if (one_xor == i) {
                return {one_xor, Zero_xor};
            }
        }
        return {Zero_xor, one_xor};
    }
};
