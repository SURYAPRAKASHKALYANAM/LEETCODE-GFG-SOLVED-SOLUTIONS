class Disjointset
{
    public:
        vector<int> parent, rank;
    Disjointset(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        rank.resize(n + 1, 0);
    }
    int ultiamteParent(int node)
    {
        if (node == parent[node]) return node;
        return parent[node] = ultiamteParent(parent[node]);
    }
    void unionFind(int u, int v)
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
            rank[ultiamteParent_u]++;
        }
    }
};

class Solution
{
    public:
        int makeConnected(int n, vector<vector < int>> &connections)
        {
            Disjointset dis(n);
            int extraConnections = 0;
            int Nocon = 0;
            for (auto it: connections)
            {
                int u = it[0], v = it[1];
                if (dis.ultiamteParent(u) == dis.ultiamteParent(v)) extraConnections++;
                else dis.unionFind(u, v);
            }
            for (int i = 0; i < n; i++)
                if (dis.parent[i] == i) Nocon++;
            Nocon--;
            if (extraConnections >= Nocon) return Nocon;
            return -1;
        }
};