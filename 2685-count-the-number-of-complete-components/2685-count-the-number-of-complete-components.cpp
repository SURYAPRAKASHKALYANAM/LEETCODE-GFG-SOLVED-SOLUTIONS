class DisJointSet {
public:
    vector<int> parent, size, edges;
    DisJointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        edges.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int ultimateParent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = ultimateParent(parent[n]);
    }

    void unionFindBySize(int u, int v) {
        int up_u = ultimateParent(u);
        int up_v = ultimateParent(v);
        if (up_u == up_v) {
            edges[up_u] += 1;
            return;
        }
        if (size[up_u] > size[up_v]) {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
            edges[up_u] += (edges[up_v] + 1);
        } else {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
            edges[up_v] += (edges[up_u] + 1);
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisJointSet ds = DisJointSet(n);
        for (auto edge : edges) {
            ds.unionFindBySize(edge[0], edge[1]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.ultimateParent(i) == i) {
                int nodes = ds.size[i];
                int edges = ds.edges[i];
                if (nodes * (nodes - 1) == (edges << 1))
                    cnt++;
            }
        }
        return cnt;
    }
};