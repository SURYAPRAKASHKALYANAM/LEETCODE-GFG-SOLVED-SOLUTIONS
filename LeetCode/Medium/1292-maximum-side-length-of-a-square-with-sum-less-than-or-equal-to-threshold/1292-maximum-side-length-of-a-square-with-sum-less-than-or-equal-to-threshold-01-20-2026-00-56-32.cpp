class Solution {
public:
    long sum(vector<vector<int>>& pref, int i, int j, int k) {
        long total = 0;
        for (int r = i; r < (i + k); r++) {
            // total += accumulate(mat[r].begin() + j, mat[r].begin() + j + k,
            // 0L);
            if (j > 0)
                total += (pref[r][j + k - 1] - pref[r][j - 1]);
            else
                total += (pref[r][j + k - 1]);
        }
        // cout << i << " " << j << " " << k << " " << total << "\n";
        return total;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pref(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0)
                    pref[i][j] = pref[i][j - 1] + mat[i][j];
                else
                    pref[i][j] = mat[i][j];
            }
        }
        int poss = min(m, n), max_len = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 1; k <= poss; k++) {
                    if ((i + k) <= m && (j + k) <= n) {
                        if (sum(pref, i, j, k) <= threshold) {
                            max_len = max(max_len, k);
                        }
                    }
                }
            }
        }
        return max_len;
    }
};