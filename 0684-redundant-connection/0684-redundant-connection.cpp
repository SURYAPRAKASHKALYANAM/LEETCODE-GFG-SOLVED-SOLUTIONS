class DisJointSet {
public:
    vector<int> parent, rank;
    DisJointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int UltimateParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = UltimateParent(parent[node]);
    }
    bool UnioFindByRank(int u, int v) {
        int ultimate_parent_u = UltimateParent(u);
        int ultimate_parent_v = UltimateParent(v);
        if (ultimate_parent_v == ultimate_parent_u)
            return false;
        if (rank[ultimate_parent_u] > rank[ultimate_parent_v]) {
            parent[ultimate_parent_v] = ultimate_parent_u;
            rank[ultimate_parent_u]++;
        } else {
            parent[ultimate_parent_u] = ultimate_parent_v;
            rank[ultimate_parent_v]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DisJointSet ds = DisJointSet(n);
        for (auto i : edges) {
            if (!ds.UnioFindByRank(i[0], i[1]))
                ans = i;
        }
        return ans;
    }
};