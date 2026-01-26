class Solution {
public:
    void bfs(int start, int n, vector<vector<int>>& adj, vector<long>& dist) {
        fill(dist.begin(), dist.end(), -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1L;
                    q.push(v);
                }
            }
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<long> distX(n), distY(n), distZ(n);

        bfs(x, n, adj, distX);
        bfs(y, n, adj, distY);
        bfs(z, n, adj, distZ);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int a = distX[i];
            int b = distY[i];
            int c = distZ[i];

            if (a == -1 || b == -1 || c == -1)
                continue;

            vector<long> d = {a, b, c};
            sort(d.begin(), d.end());

            if (d[0] * d[0] + d[1] * d[1] == d[2] * d[2]) {
                cnt++;
            }
        }
        return cnt;
    }
};