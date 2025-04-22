class Solution
{
    public:
        int networkDelayTime(vector<vector < int>> &edges, int n, int k)
        {
            vector<int> dis(n+1, 1e8);
            dis[0]=0;
            dis[k] = 0;
            int m = edges.size();
            for (int i = 0; i < n - 1; i++)
            {

                for (int j = 0; j < m; j++)
                {

                    int u = edges[j][0];

                    int v = edges[j][1];

                    int wt = edges[j][2];

                    if (dis[u] != 1e8 && ((dis[u] + wt) < dis[v]))
                    {

                        dis[v] = dis[u] + wt;
                    }
                }
            }
            int max = *max_element(dis.begin(), dis.end());
            return (max == 1e8) ? -1 : max;
        }
};