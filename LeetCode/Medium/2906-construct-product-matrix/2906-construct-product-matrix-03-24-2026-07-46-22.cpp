class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 12345;
        vector<int> flat, pref(n * m), suff(n * m);
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int num : grid[i]) {
                flat.emplace_back(num);
            }
        }
        long long prod = 1LL;
        for (int i = 0; i < (n * m); i++) {
            if ((i - 1) >= 0)
                prod *= flat[i - 1];
            prod %= mod;
            pref[i] = prod;
        }
        prod = 1;
        for (int i = (n * m) - 1; i >= 0; i--) {
            if (i + 1 < (n * m))
                prod *= flat[i + 1];
            prod %= mod;
            suff[i] = prod;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int idx = i * m + j;
                ans[i][j] = (1LL * pref[idx] * suff[idx]) % mod;
            }
        }
        return ans;
    }
};