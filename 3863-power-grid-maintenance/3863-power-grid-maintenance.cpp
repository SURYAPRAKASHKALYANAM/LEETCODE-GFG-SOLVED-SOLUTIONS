class DisJointSet {
    vector<int> parent, size;

public:
    DisJointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int ultimateParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = ultimateParent(parent[node]);
    }
    void unionFindBySize(int u, int v) {
        int ultimatParentOfU = ultimateParent(u);
        int ultimatParentOfV = ultimateParent(v);
        if (ultimatParentOfU == ultimatParentOfV)
            return;
        if (size[ultimatParentOfU] >= size[ultimatParentOfV]) {
            parent[ultimatParentOfV] = ultimatParentOfU;
            size[ultimatParentOfU] += size[ultimatParentOfV];
        } else {
            parent[ultimatParentOfU] = ultimatParentOfV;
            size[ultimatParentOfV] += size[ultimatParentOfU];
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DisJointSet ds = DisJointSet(c);
        // unordered_map<int,priority_queue<int,vector<int>,greater<int>>>
        // grids;
        unordered_map<int, set<int>> grids;
        for (auto& i : connections) {
            ds.unionFindBySize(i[0], i[1]);
        }
        for (int i = 1; i <= c; i++) {
            int ultimateParent = ds.ultimateParent(i);
            grids[ultimateParent].insert(i);
        }
        vector<int> ans;
        for (auto& i : queries) {
            int ultimateParent = ds.ultimateParent(i[1]);
            if (i[0] == 1) {
                if (grids[ultimateParent].count(i[1])) {
                    ans.emplace_back(i[1]);
                } else if (grids[ultimateParent].size()) {
                    ans.emplace_back(*grids[ultimateParent].begin());
                } else {
                    ans.emplace_back(-1);
                }
            } else {
                if (grids[ultimateParent].count(i[1])) {
                    grids[ultimateParent].erase(i[1]);
                }
            }
        }
        return ans;
    }
};