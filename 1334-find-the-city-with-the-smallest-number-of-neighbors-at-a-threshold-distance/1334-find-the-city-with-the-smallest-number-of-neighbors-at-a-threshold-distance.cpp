class Solution
{
    public:
        int findTheCity(int V, vector<vector < int>> &edges, int distanceThreshold)
        {
            vector<vector < int>> matrix(V, vector<int> (V + 1, 1e9));
            int e = edges.size();
            for (int i = 0; i < e; i++)
            {
                int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
                matrix[v][u] = matrix[u][v] = wt;
            }
            for (int via = 0; via < V; via++)
            {
                matrix[via][via] = 0;
                for (int i = 0; i < V; i++)
                {
                    for (int j = 0; j < V; j++)
                    {
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    }
                }
            }
            int cnt_max = INT_MAX, node = -1;
            for (int i = 0; i < V; i++)
            {
                int cnt = 0;
                for (int j = 0; j < V; j++)
                {
                    if (matrix[i][j] <= distanceThreshold && i != j) cnt++;
                }
                if (cnt <= cnt_max)
                {
                    cnt_max = cnt;
                    node =i;
                }
            }
            return node;
        }
};