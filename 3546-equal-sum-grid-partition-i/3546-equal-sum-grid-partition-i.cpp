class Solution {
public:
    bool partition(vector<long long>& prefSum, int& len) {
        for (int i = 0; i < len; i++) {
            if (prefSum[i] == (prefSum[len - 1] - prefSum[i]))
                return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rowSum(m, 0), colSum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
            if (i > 0)
                rowSum[i] += rowSum[i - 1];
        }
        for (int i = 1; i < n; i++)
            colSum[i] += colSum[i - 1];
        return partition(rowSum, m) || partition(colSum, n);
    }
};