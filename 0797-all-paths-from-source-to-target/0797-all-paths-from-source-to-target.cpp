class Solution
{
    public:
        void dfs(int node, int target, vector<vector < int>> &graph, vector< int > &dfss, vector< vector< int>> &ans)
        {
            dfss.push_back(node);
            if (node == target) ans.push_back(dfss);
            for (auto i: graph[node])
            {
                dfs(i, target, graph, dfss, ans);
                dfss.pop_back();
            }
    }
    vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
    {
        vector<vector < int>> ans;
        vector<int> path;
        int node = 0, target = graph.size() - 1;
        dfs(node, target, graph, path, ans);
        return ans;
    }
};