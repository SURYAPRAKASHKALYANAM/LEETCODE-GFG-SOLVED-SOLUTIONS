class Solution
{
    public:
        void dfs(int nodes, int noded, vector<vector < int>> &adjs,
            vector<vector < int>> &connected, vector< int > visited)
        {
            if (visited[noded] || connected[nodes][noded])
                return;
            visited[noded] = 1;
            connected[nodes][noded] = 1;
            for (auto i: adjs[noded])
                dfs(nodes, i, adjs, connected, visited);
            return;
        }
    vector<bool> checkIfPrerequisite(int numCourses,
        vector<vector < int>> &prerequisites,
        vector<vector < int>> &queries)
    {
        vector<vector < int>> adj(numCourses),
            connected(numCourses, vector<int> (numCourses, 0));
        for (auto i: prerequisites)
            adj[i[0]].emplace_back(i[1]);
        for (int i = 0; i < numCourses; i++)
        {
            vector<int> visited(numCourses, 0);
            dfs(i, i, adj, connected, visited);
        }
        vector<bool> ans;
        for (auto i: queries)
            ans.emplace_back(connected[i[0]][i[1]]);
        return ans;
    }
};