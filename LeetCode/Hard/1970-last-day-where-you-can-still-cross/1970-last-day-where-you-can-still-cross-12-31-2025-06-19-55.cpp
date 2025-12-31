class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int isLastDay(int& day, int& row, int& col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        // mark every water
        for (int i = 0; i < day; i++)
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        queue<pair<int, int>> q; // bfs

        // we can start from first row
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                q.push({0, i});
                grid[0][i] = 1;
            }
        }

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top.first == row - 1)
                return true;
            for (int i = 0; i < 4; i++) {
                int nr = top.first + dx[i], nc = top.second + dy[i];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // let's water it , so we don't come back
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int start = 0, end = row * col, mid;
        while (start < end - 1) {
            mid = start + (end - start) / 2;
            if (isLastDay(mid, row, col, cells)) {
                start = mid;
            } else
                end = mid;
        }
        return start;
    }
};