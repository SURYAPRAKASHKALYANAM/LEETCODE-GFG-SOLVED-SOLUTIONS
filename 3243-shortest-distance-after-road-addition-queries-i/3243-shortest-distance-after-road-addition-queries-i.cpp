class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++) adj[i].emplace_back(i+1);
        vector<int> ans;
        for(auto i:queries)
        {
            adj[i[0]].emplace_back(i[1]);
            int min_dis=INT_MAX;
            queue<pair<int,int>> q;
            unordered_map<int,int> vis;
            vis[0]=1;
            q.push({0,0});
            while(!q.empty())
            {
                auto it=q.front();q.pop();
                int steps=it.second;
                if(it.first==n-1)
                {
                    min_dis=min(min_dis,steps);
                    break;
                }
                for(auto next:adj[it.first])
                {
                    if(!vis[next])
                    {
                        q.push({next,steps+1});
                        vis[next]=1;
                    }
                }
            }
            ans.emplace_back(min_dis);
        }
        return ans;
    }
};