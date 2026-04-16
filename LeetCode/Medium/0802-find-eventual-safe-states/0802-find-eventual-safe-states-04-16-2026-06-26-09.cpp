class Solution {
public:
    bool dfs(int node, vector<int>& isSafe, vector<vector<int>>& graph) {
        if (isSafe[node] == 0)
            return false;
        if (isSafe[node] == 1)
            return true;
        isSafe[node] = 0;
        for (int child : graph[node]) {
            if (!dfs(child, isSafe, graph))
                return false;
        }
        isSafe[node] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> isSafe(V, -1);
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (isSafe[i] == -1) {
                dfs(i, isSafe, graph);
            }
        }
        for (int i = 0; i < V; i++) {
            if (isSafe[i] == 1) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};