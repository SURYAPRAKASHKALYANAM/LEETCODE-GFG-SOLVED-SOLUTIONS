// OPTIMAL
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), connected = 0;
        vector<int> rowones(m, 0), colones(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    rowones[i]++, colones[j]++;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                connected += (grid[i][j]) && (colones[j] > 1 || rowones[i] > 1);
        return connected;
    }
};
// DISJOINT SET
// class DisJointSet {
// public:
//     vector<int> parent, rank;
//     map<int, vector<int>> connections;
//     DisJointSet(int n) {
//         rank.resize(n+1, 0);
//         parent.resize(n+1);
//         for (int i = 0; i <= n; i++)
//             parent[i] = i;
//     }

//     int UltimateParent(int node) {
//         if (node==parent[node])
//             return node;
//         return parent[node] = UltimateParent(parent[node]);
//     }

//     void UnioinFindRank(int u, int v) {
//         int ultimateparent_u = UltimateParent(u);
//         int ultimateparent_v = UltimateParent(v);
//         if (ultimateparent_u == ultimateparent_v)
//             return;
//         if (rank[ultimateparent_u] > rank[ultimateparent_v]) {
//             parent[ultimateparent_v] = ultimateparent_u;
//             connections[ultimateparent_u].emplace_back(ultimateparent_v);
//             if (connections[ultimateparent_v].size()) {
//                 connections[ultimateparent_u].reserve(
//                     connections[ultimateparent_u].size() +
//                     distance(connections[ultimateparent_v].begin(),
//                              connections[ultimateparent_v].end()));
//                 connections[ultimateparent_u].insert(
//                     connections[ultimateparent_u].end(),
//                     connections[ultimateparent_v].begin(),
//                     connections[ultimateparent_v].end());
//             }
//         } else if (rank[ultimateparent_u] < rank[ultimateparent_v]) {
//             parent[ultimateparent_u] = ultimateparent_v;
//             connections[ultimateparent_v].emplace_back(ultimateparent_u);
//             if (connections[ultimateparent_u].size()) {
//                 connections[ultimateparent_v].reserve(
//                     connections[ultimateparent_v].size() +
//                     distance(connections[ultimateparent_u].begin(),
//                              connections[ultimateparent_u].end()));
//                 connections[ultimateparent_v].insert(
//                     connections[ultimateparent_v].end(),
//                     connections[ultimateparent_u].begin(),
//                     connections[ultimateparent_u].end());
//             }
//         } else {
//             parent[ultimateparent_v] = ultimateparent_u;
//             connections[ultimateparent_u].emplace_back(ultimateparent_v);
//             if (connections[ultimateparent_v].size()) {
//                 connections[ultimateparent_u].reserve(
//                     connections[ultimateparent_u].size() +
//                     distance(connections[ultimateparent_v].begin(),
//                              connections[ultimateparent_v].end()));
//                 connections[ultimateparent_u].insert(
//                     connections[ultimateparent_u].end(),
//                     connections[ultimateparent_v].begin(),
//                     connections[ultimateparent_v].end());
//             }
//             rank[ultimateparent_u]++;
//         }
//     }
// };
// class Solution {
// public:
//     int countServers(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         DisJointSet ds = DisJointSet(n * m);
//         for (int i = 0; i < m; i++) {
//             int prev = -1;
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j]) {
//                     if (prev == -1) {
//                         prev = i * m + j;
//                     } else {
//                         ds.UnioinFindRank(prev, i * m + j);
//                     }
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             int prev = -1;
//             for (int j = 0; j < m; j++) {
//                 if (grid[j][i]) {
//                     if (prev == -1) {
//                         prev = j * m + i;
//                     } else {
//                         ds.UnioinFindRank(prev, j * m + i);
//                     }
//                 }
//             }
//         }
//         int cnt = 0;
//         for (int i = 0; i < m * n; i++) {
//             cout << endl << i << "->";
//             if (ds.UltimateParent(i) == i && ds.connections[i].size()) {
//                 for (auto j : ds.connections[i])
//                     cout << j << " ";
//                 cnt += ds.connections[i].size() + 1;
//             }
//         }
//         return cnt;
//     }
// };