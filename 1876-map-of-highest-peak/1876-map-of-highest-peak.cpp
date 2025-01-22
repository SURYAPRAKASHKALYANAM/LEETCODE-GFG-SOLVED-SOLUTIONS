class Solution
{
    public:
        vector<vector < int>> highestPeak(vector<vector < int>> &isWater)
        {
            int m = isWater.size(), n = isWater[0].size();
            vector<vector < int>> height(m, vector<int> (n, 0));
            queue<pair<int, pair<int, int>>> q;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (isWater[i][j])
                   	q.push({0, {i, j}});
                }
            }
           	int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
            while (!q.empty())
            {
                auto it = q.front();
                q.pop();
                int dist = it.first, r = it.second.first, c = it.second.second;
                for (int i = 0; i < 4; i++)
                {
                    int row = r + dx[i], col = c + dy[i];
                    if (row >= 0 && row < m && col >= 0 && col < n)
                    {
                        if ((dist + 1 < height[row][col] || !height[row][col]) &&
                            !isWater[row][col])
                        {
                            height[row][col] = dist + 1;
                           	q.push({dist + 1, {row, col}});
                        }
                    }
                }
            }
            return height;
        }
};