class Solution {
public:
    long long powerOfTwoMod(long long exponent, long long modulus) {
        long long result = 1;
        long long base = 2 % modulus;
        while (exponent > 0) {
            if (exponent % 2 == 1)
                result = (result * base) % modulus;
            base = (base * base) % modulus;
            exponent /= 2;
        }
        return result;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 2;
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> dis(n, 1e9);
        queue<int> q;
        dis[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : adj[node]) {
                if (dis[next] > 1 + dis[node]) {
                    dis[next] = 1 + dis[node];
                    q.push(next);
                }
            }
        }
        int max_depth = *max_element(dis.begin() + 1, dis.end());
        return powerOfTwoMod(max_depth - 1, 1e9 + 7);
    }
};