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
    void UnioFindByRank(int& ultimate_parent_u, int& ultimate_parent_v) {
        if (rank[ultimate_parent_u] > rank[ultimate_parent_v]) {
            parent[ultimate_parent_v] = ultimate_parent_u;
        } else if (rank[ultimate_parent_v] > rank[ultimate_parent_u]) {
            parent[ultimate_parent_u] = ultimate_parent_v;
        } else {
            parent[ultimate_parent_v] = ultimate_parent_u;
            rank[ultimate_parent_u]++;
        }
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](vector<int>& e1, vector<int>& e2) {
            if (e1[3] == e2[3])
                return e1[2] > e2[2];
            return e1[3] > e2[3];
        });
        DisJointSet ds(n);
        int min_strength = 1e7, mst_edges = 0;
        vector<int> st;
        for (auto& edge : edges) {
            int ultimate_parent_u = ds.UltimateParent(edge[0]);
            int ultimate_parent_v = ds.UltimateParent(edge[1]);
            if (edge[3] == 1) {
                if (ultimate_parent_u != ultimate_parent_v) {
                    min_strength = min(min_strength, edge[2]);
                    ds.UnioFindByRank(ultimate_parent_u, ultimate_parent_v);
                    mst_edges++;
                } else
                    return -1;
            } else {
                if (ultimate_parent_u != ultimate_parent_v) {
                    st.push_back(edge[2]);
                    ds.UnioFindByRank(ultimate_parent_u, ultimate_parent_v);
                    mst_edges++;
                }
            }
        }
        if (mst_edges != n - 1)
            return -1;
        sort(st.begin(), st.end());
        if (!st.empty() && min_strength < st[0])
            return min_strength;

        for (int& e : st) {
            if (min_strength < e)
                break;
            min_strength = min(min_strength, k > 0 ? e * 2 : e);
            k--;
        }

        return min_strength;
    }
};