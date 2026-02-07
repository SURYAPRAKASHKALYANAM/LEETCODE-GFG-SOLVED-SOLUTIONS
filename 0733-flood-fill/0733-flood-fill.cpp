class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> temp = image;
        int m = image.size(), n = image[0].size();
        int srcClr = image[sr][sc];
        if (srcClr == color)
            return temp;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        queue<pair<int, int>> q;
        temp[sr][sc] = color;
        q.push({sr, sc});
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dr = r + dx[i], dc = c + dy[i];
                if (dr >= 0 && dr < m && dc >= 0 && dc < n &&
                    temp[dr][dc] == srcClr) {
                    temp[dr][dc] = color;
                    q.push({dr, dc});
                }
            }
        }
        return temp;
    }
};