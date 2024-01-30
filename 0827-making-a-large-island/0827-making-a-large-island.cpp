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
class Solution
{
    public:
        int largestIsland(vector<vector < int>> &grid)
        {
            int n = grid.size();
            Disjointset dis(n *n);
            int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j])
                    {
                        int currNode = i *n + j;
                        for (int ii = 0; ii < 4; ii++)
                        {
                            int row = i + delrow[ii], col = j + delcol[ii];
                            int adjnode = row *n + col;
                            if (row >= 0 && col >= 0 && row < n && col < n && grid[row][col])
                            {
                                if (dis.ultiamteParent(currNode) != dis.ultiamteParent(adjnode)) dis.unionFindSize(currNode, adjnode);
                            }
                        }
                    }
                }
            }
            int cnt_max = *max_element(dis.size.begin(), dis.size.end());
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!grid[i][j])
                    {
                        int cnt = 1;
                        set<int> s;
                        for (int ii = 0; ii < 4; ii++)
                        {
                            int row = i + delrow[ii], col = j + delcol[ii];
                            if (row >= 0 && col >= 0 && row < n && col < n && grid[row][col])
                            {
                                s.insert(dis.ultiamteParent(row *n + col));
                            }
                        }
                        for (auto adjnode: s) cnt += dis.size[dis.ultiamteParent(adjnode)];
                        cnt_max = max(cnt_max, cnt);
                    }
                }
            }
            return cnt_max;
        }
};