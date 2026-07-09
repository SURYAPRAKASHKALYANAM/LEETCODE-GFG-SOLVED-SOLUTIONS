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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        DisJointSet ds = DisJointSet(n);
        vector<bool> ans(queries.size());
        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                ds.UnioFindByRank(i, i - 1);
            }
        }
        int i = 0;
        for (auto query : queries) {
            ans[i++] = (ds.UltimateParent(query[0]) == ds.UltimateParent(query[1]));
        }

        return ans;
    }
};