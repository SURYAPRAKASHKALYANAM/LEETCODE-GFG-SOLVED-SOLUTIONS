class Disjointset
{
    private:
        vector<int> size, parent;

    public:
        Disjointset(int n)
        {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
    int ultimateParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = ultimateParent(parent[u]);
    }
    int sizeofu(int u)
    {
        return size[ultimateParent(u)];
    }
    void unioinFindBySize(int u, int v)
    {
        int ultimate_parent_u = ultimateParent(u);
        int ultimate_parent_v = ultimateParent(v);
        if (ultimate_parent_u == ultimate_parent_v)
            return;
        if (size[ultimate_parent_u] < size[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v] += size[ultimate_parent_u];
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }
    }
};
class Solution
{
    public:
        int largestIsland(vector<vector < int>> &grid)
        {
            int n = grid.size();
            Disjointset ds = Disjointset(n *n);
            vector<vector < int>> visited(n, vector<int> (n, 0));
            int max_island = INT_MIN, curr;
           	int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] && !visited[i][j])
                    {
                        queue<int> q;
                        q.push(i *n + j);
                        while (!q.empty())
                        {
                            auto node = q.front();
                            q.pop();
                            int x = node / n, y = node % n;
                            if (visited[x][y])
                                continue;
                            visited[x][y] = 1;
                            for (int d = 0; d < 4; d++)
                            {
                                int r = x + dx[d], c = y + dy[d];
                                if (r >= 0 && r < n && c >= 0 && c < n &&
                                    !visited[r][c] && grid[r][c])
                                {
                                    ds.unioinFindBySize(i *n + j, r *n + c);
                                    q.push(r *n + c);
                                }
                            }
                        }
                        max_island = max(max_island, ds.sizeofu(i *n + j));
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!grid[i][j])
                    {
                        set<int> st;
                        curr = 1;
                        for (int d = 0; d < 4; d++)
                        {
                            int r = dx[d] + i, c = dy[d] + j;
                            if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c])
                            {
                                int ultimate_parent_u =
                                    ds.ultimateParent(r *n + c);
                                if (!st.count(ultimate_parent_u))
                                    curr += ds.sizeofu(ultimate_parent_u);
                                st.insert(ultimate_parent_u);
                            }
                        }
                        max_island = max(max_island, curr);
                    }
                }
            }
            return max_island;
        }
};