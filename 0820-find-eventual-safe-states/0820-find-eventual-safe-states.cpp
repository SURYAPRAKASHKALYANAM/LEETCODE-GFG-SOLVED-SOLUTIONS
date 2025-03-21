class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& graph) {
        if (visited[node] == 1 || graph[node].size() == 0)
            return true;
        if (visited[node] == 0)
            return false;
        visited[node] = 0;
        for (auto next : graph[node]) {
            if (visited[next] == 0 || dfs(next, visited, graph) == 0)
                return false;
        }
        visited[node] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1 && dfs(i, visited, graph)) {
                visited[i] = 1;
                ans.emplace_back(i);
            } else if (visited[i] == 1)
                ans.emplace_back(i);
        }
        return ans;
    }
};