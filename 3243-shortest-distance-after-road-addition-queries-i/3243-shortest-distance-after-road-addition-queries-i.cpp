class Solution
{
    public:
       	// vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
       	//     vector<vector < int>> adj(n);
       	//     for(int i=0;i < n-1;i++) adj[i].emplace_back(i+1);
       	//     vector<int> ans;
       	//     for(auto i:queries)
       	//     {
       	//         adj[i[0]].emplace_back(i[1]);
       	//         int min_dis=INT_MAX;
       	//         queue<pair<int,int>> q;
       	//         unordered_map<int,int > vis;
       	//         vis[0]=1;
       	//         q.push({0,0});
       	//         while(!q.empty())
       	//         {
       	//             auto it=q.front();q.pop();
       	//             int steps=it.second;
       	//             if(it.first==n-1)
       	//             {
       	//                 min_dis=min(min_dis,steps);
       	//                 break;
       	//             }
       	//             for(auto next:adj[it.first])
       	//             {
       	//                 if(!vis[next])
       	//                 {
       	//                     q.push({next,steps+1});
       	//                     vis[next]=1;
       	//                 }
       	//             }
       	//         }
       	//         ans.emplace_back(min_dis);
       	//     }
       	//     return ans;
       	// }
       	// OPTIMAL DP+DIJK
        vector<int> shortestDistanceAfterQueries(int n, vector<vector < int>> &queries)
        {
            vector<vector < int>> roads(n);
            vector<int> dp(n), res;
            iota(begin(dp), end(dp), 0);
            for (const auto &q: queries)
            {
                roads[q[1]].push_back(q[0]);
                for (int i = q[1]; i < n; ++i)
                {
                    dp[i] = min(dp[i], dp[i - 1] + 1);
                    for (int l: roads[i])
                        dp[i] = min(dp[i], dp[l] + 1);
                }
                res.push_back(dp[n - 1]);
            }
            return res;
        }
};