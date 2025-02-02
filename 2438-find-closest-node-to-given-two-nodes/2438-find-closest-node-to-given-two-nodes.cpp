class Solution
{
    public:
        int closestMeetingNode(vector<int> &edges, int node1, int node2)
        {
            int n = edges.size();
            vector<int> dis1(n, INT_MAX), dis2(n, INT_MAX), visited(n, 0);
            queue<pair<int, int>> q;
           	q.push({ node1,0 });
            visited[node1] = 1;
            while (!q.empty())
            {
                auto it = q.front();
                q.pop();
                int node = it.first, dis = it.second;
                dis1[node] = min(dis1[node], dis);
                int next = edges[node];
                if (next != -1 && !visited[next])
                {
                    visited[next] = 1;
                   	q.push({next, dis1[node] + 1});
                }
            }
            fill(begin(visited), end(visited), 0);
           	q.push({node2, 0});
            visited[node2] = 1;
            while (!q.empty())
            {
                auto it = q.front();
                q.pop();
                int node = it.first, dis = it.second;
                dis2[node] = min(dis2[node], dis);
                int next = edges[node];
                if (next != -1 && !visited[next])
                {
                    visited[next] = 1;
                   	q.push({next, dis2[node] + 1});
                }
            }
            int ans = -1, mini_max_dis = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (dis1[i] != INT_MAX && dis2[i] != INT_MAX)
                {
                    if (mini_max_dis > max(dis1[i], dis2[i]))
                    {
                        mini_max_dis = max(dis1[i], dis2[i]);
                        ans = i;
                    }
                }
            }
            return ans;
        }
};