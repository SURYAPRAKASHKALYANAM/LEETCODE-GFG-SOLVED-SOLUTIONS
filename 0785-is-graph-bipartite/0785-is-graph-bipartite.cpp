class Solution
{
    public:
        bool bfs(int node, vector<vector < int>> &adj, vector< int > &visited, int color)
        {
            visited[node] = color;
            queue<int> q;
            q.push(node);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it: adj[node])
                {
                    if (visited[it] == -1)
                    {
                        visited[it] = !visited[node];
                        q.push(it);
                    }
                    else if (visited[it] == visited[node])
                        return false;
                }
            }
            return true;
        }
    bool isBipartite(vector<vector < int>> &adj)
    {
        int V = adj.size();
        vector<int> visited(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == -1)
            {
                if (bfs(i, adj, visited, 0) == false) return false;
            }
        }
        return true;
    }
};