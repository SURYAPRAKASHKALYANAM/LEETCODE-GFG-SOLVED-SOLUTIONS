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
    void reset(int u)
    {
        parent[u] = u;
    }
};

class Solution
{
    public:
        vector<int> findAllPeople(int n, vector<vector < int>> &meetings, int firstPerson)
        {
            Disjointset ds(n);
            priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            for(auto i:meetings)
            {
                pq.push({i[2],{i[0],i[1]}});
            }
            ds.unionFindSize(0, firstPerson);
            vector<int> temp;
            while (!pq.empty())
            {
                auto it = pq.top();
                int t = it.first;
                int curr = t;
                temp.clear();
                while (!pq.empty())
                {
                    auto it = pq.top();
                    curr = it.first;
                    if (curr != t) break;
                    temp.emplace_back(it.second.first);
                    temp.emplace_back(it.second.second);
                    ds.unionFindSize(it.second.first, it.second.second);
                   	// cout<<it.second.first<<" "<<it.second.second<<endl;
                   	// cout<<ds.ultiamteParent(it.second.first)<<" "<< ds.ultiamteParent(it.second.second)<<endl;
                    if (curr == t) pq.pop();
                }
                for (auto i: temp)
                {
                    if (ds.ultiamteParent(i) != ds.ultiamteParent(0)) ds.reset(i);
                }
            }
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                if (ds.ultiamteParent(i) == ds.ultiamteParent(0)) ans.emplace_back(i);
               	// cout<<ds.parent[i]<<endl;
            }
            return ans;
        }
};