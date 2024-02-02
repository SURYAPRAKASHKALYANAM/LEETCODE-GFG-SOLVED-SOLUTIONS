class Solution
{
    public:
        int shortestPathBinaryMatrix(vector<vector < int>> &grid)
        {
            int n = grid.size();
            if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
            pair<int,int> source={0,0},destination={n-1,n-1};
            set<pair<int, pair<int, int>>> s;
            s.insert({ 1,{ 0,0 } });
            vector<vector < int>> mindis(n, vector<int> (n, 1e9));
            mindis[0][0] = 1;
            while (!s.empty())
            {
                auto it = *(s.begin());
                s.erase(it);
                int dis = it.first, r = it.second.first, c = it.second.second;
                if (r == n - 1 && c == n - 1) return dis;
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int row = r + i, col = c + j;
                        if (row >= 0 && row < n && col >= 0 && col < n && !grid[row][col])
                        {
                            if (dis + 1 < mindis[row][col])
                            {
                                if (mindis[row][col] != 1e9) s.erase({ mindis[row][col],{row,col} });
                                mindis[row][col] = dis + 1;
                                s.insert({ mindis[row][col],{row,col} });
                            }
                        }
                    }
                }
            }
            return (mindis[n - 1][n - 1] == 1e9) ? -1 : mindis[n - 1][n - 1];
        }
};