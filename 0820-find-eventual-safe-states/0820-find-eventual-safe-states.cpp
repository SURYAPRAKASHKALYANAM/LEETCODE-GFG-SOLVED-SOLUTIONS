class Solution {
public:
    vector<int> checked;
    bool isSafe(int node, vector<vector<int>>& graph, vector<int> visited) {
        if (!graph[node].size() || checked[node]==1)
            return true;
        if (visited[node] == 1 || checked[node]==0)
            return false;
        visited[node] = 1;
        for (auto next : graph[node]) {
            if (!isSafe(next, graph, visited))
                return checked[next] = false;
        }
        visited[node] = 0;
        return checked[node] = true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        checked.resize(n, -1);
        vector<int> ans, visited(n, 0);
        for (int i = 0; i < n; i++) {
            checked[i] = (!graph[i].size() || isSafe(i, graph, visited));
            if (checked[i])
                ans.emplace_back(i);
        }
        return ans;
    }
};