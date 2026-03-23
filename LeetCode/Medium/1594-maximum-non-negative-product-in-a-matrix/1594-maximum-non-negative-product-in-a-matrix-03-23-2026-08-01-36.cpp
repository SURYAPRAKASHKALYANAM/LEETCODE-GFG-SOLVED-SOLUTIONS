class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<long long, long long>>> prod(
            m, vector<pair<long long, long long>>(n, {LLONG_MAX, LLONG_MIN}));
        int mod = 1e9 + 7;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0) {
                    long long prevMin = 1LL * prod[i - 1][j].first,prevMax = 1LL * prod[i - 1][j].second,
                              curr = 1LL * grid[i][j];
                    long long currProdMin = min(prevMin * curr, prevMax * curr);
                    long long currProdMax = max(prevMin * curr, prevMax * curr);
                    prod[i][j].first = min(currProdMin, prod[i][j].first);
                    prod[i][j].second = max(currProdMax, prod[i][j].second);
                }
                if (j - 1 >= 0) {
                    long long prevMin = 1LL * prod[i][j - 1].first,prevMax = 1LL * prod[i][j - 1].second,
                              curr = 1LL * grid[i][j];
                    long long currProdMin = min(prevMin * curr, prevMax * curr);
                    long long currProdMax = max(prevMin * curr, prevMax * curr);
                    prod[i][j].first = min(currProdMin, prod[i][j].first);
                    prod[i][j].second = max(currProdMax, prod[i][j].second);
                }
                if (i - 1 < 0 && j - 1 < 0)
                    prod[i][j] = {grid[i][j], grid[i][j]};
                // auto it = prod[i][j];
                // cout << it.first << " " << it.second << "\n";
            }
        }
        return prod[m - 1][n - 1].second < 0 ? -1
                                             : prod[m - 1][n - 1].second % mod;
    }
};