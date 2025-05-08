class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        using pi = pair<int, pair<int, int>>;
        priority_queue<pi, vector<pi>, greater<pi>> q;
        q.push({0, {1, 0}});
        time[0][0] = 0;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto it = q.top();
            int currt = it.first, step = it.second.first,
                pos = it.second.second;
            int x = pos / m, y = pos % m;
            q.pop();
            if (x == n - 1 && y == m - 1)
                break;
            for (int i = 0; i < 4; i++) {
                int row = x + dx[i], col = y + dy[i];
                if (min(row, col) >= 0 && row < n && col < m) {
                    if (time[row][col] > (currt + step)) {
                        if (currt >= moveTime[row][col]) {
                            time[row][col] = currt + step;
                        } else {
                            time[row][col] = moveTime[row][col] + step;
                        }
                        q.push(
                            {time[row][col], {(step & 1) + 1, row * m + col}});
                    }
                }
            }
        }
        return time[n - 1][m - 1] == INT_MAX ? -1 : time[n - 1][m - 1];
    }
};