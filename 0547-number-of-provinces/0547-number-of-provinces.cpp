class Solution
{
    private:
        void bfs(int nrow ,vector<vector < int>> &grid, vector< int > &visited)
        {
            queue<int> q;
            q.push(nrow);
            while (!q.empty())
            {
                int row = q.front();
                q.pop();
                for (auto it: grid[row])
                {
                    if (!visited[it])
                    {
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    public:
        int findCircleNum(vector<vector < int>> &isConnected)
        {
            vector<int> visited(isConnected.size(), 0);
            vector<vector < int>> grid(isConnected.size());
            for (int row = 0; row < isConnected.size(); row++)
            {
                for (int col = 0; col < isConnected.size(); col++)
                {
                    if (isConnected[row][col] == 1 && row != col) grid[row].emplace_back(col);
                }
            }
            int cnt = 0;
            for (int row = 0; row < grid.size(); row++)
            {
                if (!visited[row])
                {
                    cnt++;
                    visited[row] = 1;
                    bfs(row, grid, visited);
                }
            }
            return cnt;
        }
};