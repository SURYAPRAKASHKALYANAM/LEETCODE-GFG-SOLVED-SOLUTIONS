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
            rank[ultiamteParent_u]++;
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
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        Disjointset dis(n);
        for(auto i:edges)
        {
            if (dis.ultiamteParent(i[0]) != dis.ultiamteParent(i[1])) dis.unionFindSize(i[0], i[1]);
        }
        return dis.ultiamteParent(source)==dis.ultiamteParent(destination);
    }
};