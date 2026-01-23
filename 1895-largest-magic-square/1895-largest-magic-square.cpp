class Solution {
public:
    bool magicSqr(vector<vector<int>>& hSum, vector<vector<int>>& vSum,
                  vector<vector<int>>& grid, int i, int j, int k) {
        int targetSum = -1;
        for (int r = i; r < (i + k); r++) {
            int sum;
            if (j > 0)
                sum = hSum[r][j + k - 1] - hSum[r][j - 1];
            else
                sum = hSum[r][j + k - 1];
            
            if (targetSum == -1) targetSum = sum; 
            else if (targetSum != sum) return false;
        }
        for (int c = j; c < (j + k); c++) {
            int sum;
            if (i > 0)
                sum = vSum[i + k - 1][c] - vSum[i - 1][c]; 
            else
                sum = vSum[i + k - 1][c];
            
            if (targetSum != sum) return false;
        }

        int d1 = 0;
        for (int x = 0; x < k; x++) {
            d1 += grid[i + x][j + x];
        }
        if (d1 != targetSum) return false;

        int d2 = 0;
        for (int x = 0; x < k; x++) {
            d2 += grid[i + x][j + k - 1 - x];
        }
        if (d2 != targetSum) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> hSum(m, vector<int>(n, 0)), vSum(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vSum[i][j] = (i > 0 ? vSum[i - 1][j] : 0) + grid[i][j];
                hSum[i][j] = (j > 0 ? hSum[i][j - 1] : 0) + grid[i][j];
            }
        }
        int poss = min(m, n);
        int max_len = 1; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = max_len + 1; k <= poss; k++) {
                    if (i + k <= m && j + k <= n) {
                        if (magicSqr(hSum, vSum, grid, i, j, k)) {
                            max_len = k;
                        }
                    }
                }
            }
        }
        return max_len;
    }
};