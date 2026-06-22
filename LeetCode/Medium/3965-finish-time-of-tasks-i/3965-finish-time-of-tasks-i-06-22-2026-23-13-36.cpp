class Solution {
public:
    long long find(int node, vector<int> adj[], vector<int>& baseTime) {
        if (adj[node].size() == 0)
            return 1LL * baseTime[node];
        long long mini = LLONG_MAX, maxi = LLONG_MIN;
        for (int next : adj[node]) {
            auto mi = find(next, adj, baseTime);
            mini = min(mi, mini);
            maxi = max(mi, maxi);
        }
        return 2LL * maxi - mini + baseTime[node];
    }
    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& baseTime) {
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
        }
        return find(0, adj, baseTime);
    }
};