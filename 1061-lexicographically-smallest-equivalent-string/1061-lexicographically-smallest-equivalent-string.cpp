class Disjontset
{
    vector<int> parent;
    public:
    Disjontset(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
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
        if (ultiamteParent_u < ultiamteParent_v) parent[ultiamteParent_v] = ultiamteParent_u;
        else parent[ultiamteParent_u] = ultiamteParent_v;
    }
};

class Solution
{
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            string ans="";
            Disjontset ds(26);
            for(int i=0;i<s1.size();i++)
            {
                ds.unionFind(s1[i]-'a',s2[i]-'a');
            }
            for(auto i:baseStr) ans+=(char)(ds.ultiamteParent(i-'a')+'a');
            return ans;
        }
};