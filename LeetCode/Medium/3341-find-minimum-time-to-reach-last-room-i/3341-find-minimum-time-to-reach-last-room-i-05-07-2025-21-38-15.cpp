class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, 1e9));
        using pii=pair<int, pair<int, int>>;
        priority_queue<pii,vector<pii>,greater<pii>> q;
        q.push({0, {0, 0}});
        time[0][0] = 0;
        int dx[] = {0, 1, -1,0}, dy[] = {1, 0, 0,-1};
        while (!q.empty()) {
            auto [currt, pos] = q.top();
            auto [r, c] = pos;
            q.pop();
            if (r == n - 1 && c == m - 1)
                continue;
            for (int i = 0; i < 4; i++) {
                int row = r + dx[i], col = c + dy[i];
                if (row >= 0 && col >= 0 && row < n && col < m) {
                    if (time[row][col] == 1e9 ||
                        (time[row][col] > (currt + 1))) {
                        if (currt >= moveTime[row][col]) {
                            time[row][col] = currt + 1;
                            q.push({time[row][col], {row, col}});
                        } else {
                            time[row][col] = moveTime[row][col] + 1;
                            q.push({time[row][col], {row, col}});
                        }
                    }
                }
            }
        }
        return time[n - 1][m - 1] != 1e9 ? time[n - 1][m - 1] : -1;
    }
};