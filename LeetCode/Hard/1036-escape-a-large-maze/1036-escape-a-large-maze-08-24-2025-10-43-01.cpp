#define bool_map_2d unordered_map<int, unordered_map<int, bool>>
class Solution {
public:
    bool_map_2d isBlocked;
    bool find(vector<int>& source, vector<int>& target, int& maxArea) {
        bool_map_2d visited;
        int r = source[0], c = source[1];
        queue<pair<int, int>> q;
        visited[r][c] = true;
        q.push({r, c});
        int area = 0;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            if (r == target[0] && c == target[1])
                return true;
            if (area > maxArea)
                return true;
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr >= 0 && nr < 1e6 && nc >= 0 && nc < 1e6) {
                    if (!visited[nr][nc] && !isBlocked[nr][nc]) {
                        visited[nr][nc] = 1;
                        area++;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                          vector<int>& target) {
        int cnt = 0;
        for (auto i : blocked) {
            cnt++;
            isBlocked[i[0]][i[1]] = true;
        }
        int maxArea = (cnt) * (cnt - 1) / 2;
        return find(source, target, maxArea) and find(target, source, maxArea);
    }
};