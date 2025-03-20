class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int, multiset<int>> m;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int index = i * n + (j);
                m[(index % n) - i].insert(grid[i][j]);
            }
        }
        int row = n - 1, col = 0;
        bool flag = true;
        for (auto anyt : m) {
            int i = row, j = col;
            if (flag) {
                for (auto it = anyt.second.rbegin(); it != anyt.second.rend();
                     it++)
                    grid[i++][j++] = *it;
            } else {
                for (auto it = anyt.second.begin(); it != anyt.second.end();
                     it++)
                    grid[i++][j++] = *it;
            }
            if (row > 0)
                row--;
            else
                flag = false, col++;
        }
        return grid;
    }
};