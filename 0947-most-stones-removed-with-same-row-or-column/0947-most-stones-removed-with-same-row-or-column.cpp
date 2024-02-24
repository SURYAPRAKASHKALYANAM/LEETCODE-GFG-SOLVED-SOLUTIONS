class Disjointset
{
    public:
        vector<int> parent, rank, size;
    Disjointset(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
    }
    int ultiamteParent(int node)
    {
        if (node == parent[node]) return node;
        return parent[node] = ultiamteParent(parent[node]);
    }
    void unionFindrank(int u, int v)
    {
        int ultiamteParent_u = ultiamteParent(u);
        int ultiamteParent_v = ultiamteParent(v);
        if (ultiamteParent_u == ultiamteParent_v) return;
        if (rank[ultiamteParent_u] > rank[ultiamteParent_v])
        {
            parent[ultiamteParent_v] = ultiamteParent_u;
        }
        else if (rank[ultiamteParent_u] < rank[ultiamteParent_v])
        {
            parent[ultiamteParent_u] = ultiamteParent_v;
        }
        else
        {
            parent[ultiamteParent_u] = ultiamteParent_v;
            rank[ultiamteParent_v]++;
        }
    }
    void unionFindSize(int u, int v)
    {
        int ultiamteParent_u = ultiamteParent(u);
        int ultiamteParent_v = ultiamteParent(v);
        if (ultiamteParent_u == ultiamteParent_v) return;
        if (size[ultiamteParent_u] > size[ultiamteParent_v])
        {
            parent[ultiamteParent_v] = ultiamteParent_u;
            size[ultiamteParent_u] += size[ultiamteParent_v];
        }
        else
        {
            parent[ultiamteParent_u] = ultiamteParent_v;
            size[ultiamteParent_v] += size[ultiamteParent_u];
        }
    }
};

class Solution
{
    public:
        int removeStones(vector<vector < int>> &stones)
        {
           	//ans = (Total Stones - no of connected Components)
            int max_row = 0, max_Col = 0;
            for (auto i: stones)
            {
                max_row = max(max_row, i[0]);
                max_Col = max(max_Col, i[1]);
            }
            Disjointset ds(max_Col + max_row + 1);
            unordered_map<int, int> stoneNodes;
            for (auto it: stones)
            {
                int noder = it[0];
                int nodec = it[1] + max_row + 1;
                ds.unionFindSize(nodec, noder);
                stoneNodes[noder] = 1;
                stoneNodes[nodec] = 1;
            }
            int n = stones.size(), cnt = 0;
            for (auto i: stoneNodes)
            {
                if (ds.ultiamteParent(i.first) == i.first) cnt++;
            }
            return n - cnt;
        }
};