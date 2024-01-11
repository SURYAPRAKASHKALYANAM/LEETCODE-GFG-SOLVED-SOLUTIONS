class Solution
{
    public:
        int detect(int src, vector<int> adj[], vector<int> &visited)
        {
            int cnt = 1;
            visited[src] = 1;
            queue<int> q;
            q.push(src);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto i: adj[node])
                {
                    if (!visited[i])
                    {
                        visited[i] = 1;
                        cnt++;
                        q.push(i);
                    }
                }
            }
            return cnt;
        }
    long long countPairs(int n, vector<vector < int>> &edges)
    {
        vector<int> visited(n, 0), provincescnt;
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].emplace_back(edges[i][1]);
            adj[edges[i][1]].emplace_back(edges[i][0]);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                provincescnt.emplace_back(detect(i, adj, visited));
            }
        }
        if (provincescnt.size() == 1) return 0;
        long long suffix[provincescnt.size()];
        suffix[provincescnt.size() - 1] = 0;
        for (int i = provincescnt.size() - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + provincescnt[i + 1];
        }
        for (int i = 0; i < provincescnt.size() - 1; i++)
        {
            ans += (long long) provincescnt[i] *suffix[i];
        }
        return ans;
    }
};