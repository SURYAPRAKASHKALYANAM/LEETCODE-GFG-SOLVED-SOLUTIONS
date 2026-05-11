class Solution {
public:
    bool isValidThreshold(int n, const vector<vector<pair<int, int>>>& adj,
                          int source, int target, int k, int threshold) {

        vector<int> dist(n, 1e9);
        deque<int> dq;

        dq.push_back(source);
        dist[source] = 0;

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            if (u == target && dist[u] <= k)
                return true;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                int cost = (weight > threshold) ? 1 : 0;

                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;

                    if (cost == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        return dist[target] <= k;
    }

    int minimumThreshold(int n, vector<vector<int>>& edges, int source,
                         int target, int k) {
        if (source == target)
            return 0;

        vector<vector<pair<int, int>>> adj(n);
        int maxWeight = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
            maxWeight = max(maxWeight, wt);
        }

        int low = 0;
        int high = maxWeight;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValidThreshold(n, adj, source, target, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};