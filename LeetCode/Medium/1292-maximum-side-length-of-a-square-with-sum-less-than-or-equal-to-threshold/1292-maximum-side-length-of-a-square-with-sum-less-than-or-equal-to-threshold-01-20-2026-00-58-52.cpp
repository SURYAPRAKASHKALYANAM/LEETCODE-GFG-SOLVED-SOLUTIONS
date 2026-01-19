class Solution {
public:
    long sum(vector<vector<int>>& pref, int i, int j, int k) {
        long total = 0;
        for (int r = i; r < (i + k); r++) {
            if (j > 0)
                total += (pref[r][j + k - 1] - pref[r][j - 1]);
            else
                total += (pref[r][j + k - 1]);
        }
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
                // for (int k = 1; k <= poss; k++) {
                int start = 1, end = poss, k;
                while (start <= end) {
                    k = (start + end) / 2;
                    if ((i + k) <= m && (j + k) <= n) {
                        int tot = sum(pref, i, j, k);
                        if (tot <= threshold) {
                            max_len = max(max_len, k);
                            start = (k + 1);
                        } else
                            end = k - 1;
                    } else
                        end = k - 1;
                }
                // }
            }
        }
        return max_len;
    }
};