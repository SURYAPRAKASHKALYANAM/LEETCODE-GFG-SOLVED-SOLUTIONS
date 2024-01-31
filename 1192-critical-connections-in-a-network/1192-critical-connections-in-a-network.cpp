class Solution
{
    public:
        int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &time, vector< int > &lowest_time, vector< vector< int>> &ans)
    {
        visited[node] = 1;
        lowest_time[node] = time[node] = timer;
        timer++;
        for (auto it: adj[node])
        {
            if (it == parent) continue;
            if (!visited[it])
            {
                dfs(it, node, adj, visited, time, lowest_time, ans);
                lowest_time[node] = min(lowest_time[node], lowest_time[it]);
                if (time[node] < lowest_time[it])
                {
                    ans.push_back({ min(node, it),
                        max(node, it) });
                }
            }
            else
            {
                lowest_time[node] = min(lowest_time[node], lowest_time[it]);
            }
        }
    }
    vector<vector < int>> criticalConnections(int n, vector<vector < int>> &connections)
    {
        vector<int> adj[n];
        for (auto i: connections)
        {
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        vector<int> time(n), lowest_time(n), visited(n, 0);
        vector<vector < int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) dfs(i, -1, adj, visited, time, lowest_time, ans);
        }
        return ans;
    }
};