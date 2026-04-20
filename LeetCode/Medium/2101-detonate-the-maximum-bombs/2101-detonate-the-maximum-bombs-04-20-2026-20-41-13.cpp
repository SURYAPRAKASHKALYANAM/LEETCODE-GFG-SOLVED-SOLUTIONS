class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& visited, int& cnt) {
        if (visited[i])
            return;
        cnt++;
        visited[i] = 1;
        for (int next : adj[i]) {
            dfs(next, adj, visited, cnt);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = i + 1; j < n; j++) {
                long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long long dx = x1 - x2;
                long long dy = y1 - y2;
                long long dis = (dx * dx) + (dy * dy);
                if (dis <= r1 * r1)
                    adj[i].emplace_back(j);
                if (dis <= r2 * r2)
                    adj[j].emplace_back(i);
            }
        }
        int maxDetonate = 1;
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            int cnt = 0;
            dfs(i, adj, visited, cnt);
            maxDetonate = max(maxDetonate, cnt);
        }
        return maxDetonate;
    }
};