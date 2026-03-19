class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        vector<vector<pair<int, int>>> cnts(m, vector<pair<int, int>>(n));
        for (int i = 0; i < m; i++) {
            int x = 0, y = 0;
            for (int j = 0; j < n; j++) {
                x += (grid[i][j] == 'X');
                y += (grid[i][j] == 'Y');
                if (i - 1 >= 0) {
                    cnts[i][j] = {x + cnts[i - 1][j].first,
                                  y + cnts[i - 1][j].second};
                } else
                    cnts[i][j] = {x, y};
                if (cnts[i][j].first > 0 &&
                    cnts[i][j].first == cnts[i][j].second)
                    cnt++;
            }
        }
        return cnt;
    }
};