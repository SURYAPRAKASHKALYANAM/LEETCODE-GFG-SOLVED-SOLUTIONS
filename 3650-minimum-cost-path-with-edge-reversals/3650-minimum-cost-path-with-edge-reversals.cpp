class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dis(n, 1e9);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], 2 * edge[2]});
        }
        queue<int> q;
        q.push(0);
        dis[0] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nextNode : adj[node]) {
                if ((dis[node] + nextNode.second) < dis[nextNode.first]) {
                    dis[nextNode.first] = dis[node] + nextNode.second;
                    q.push(nextNode.first);
                }
            }
        }
        return dis[n - 1] == 1e9 ? -1 : dis[n - 1];
    }
};