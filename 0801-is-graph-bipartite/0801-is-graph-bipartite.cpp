class Solution
{
    public:
        bool dfs(int node, vector<vector < int>> &graph, vector< int > &visited)
        {
            for (auto next: graph[node])
            {
                if (visited[next] == -1)
                {
                    visited[next] = !visited[node];
                    if (!dfs(next, graph, visited)) return false;
                }
                else if (visited[next] == visited[node]) return false;
            }
            return true;
        }
    bool isBipartite(vector<vector < int>> &graph)
    {
        int n = graph.size();
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() && visited[i] == -1)
            {
                visited[i] = 0;
                if (!dfs(i, graph, visited)) return false;
            }
        }
        return true;
    }
};