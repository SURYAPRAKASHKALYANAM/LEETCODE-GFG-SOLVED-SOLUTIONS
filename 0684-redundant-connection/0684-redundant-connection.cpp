class Disjointset{
    vector<int> parent,rank;
    public:
    Disjointset(int n)
    {
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        rank.resize(n+1,0);
    }
    int ultiamteParent(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=ultiamteParent(parent[node]);
    }
    void unionFind(int u,int v)
    {
        int ultiamteParent_u=ultiamteParent(u);
        int ultiamteParent_v=ultiamteParent(v);
        if(ultiamteParent_u==ultiamteParent_v) return;
        if(rank[ultiamteParent_u]>rank[ultiamteParent_v])
        {
            parent[ultiamteParent_v]=ultiamteParent_u;
        }
        else if(rank[ultiamteParent_u]<rank[ultiamteParent_v])
        {
            parent[ultiamteParent_u]=ultiamteParent_v;
        }
        else
        {
            parent[ultiamteParent_u]=ultiamteParent_v;
            rank[ultiamteParent_u]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Disjointset dis(1000);
        vector<int> ans;
        for(auto i:edges)
        {
            if(dis.ultiamteParent(i[0])!=dis.ultiamteParent(i[1])) dis.unionFind(i[0],i[1]);
            else ans=i;
        }
        return ans;
    }
};