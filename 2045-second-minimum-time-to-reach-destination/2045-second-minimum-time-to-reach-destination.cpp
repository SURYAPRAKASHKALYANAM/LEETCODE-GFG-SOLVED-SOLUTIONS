class Solution
{
    public:
        int secondMinimum(int n, vector<vector < int>> &edges, int time, int change)
        {
            vector<vector < int>> adj(n + 1);
            for (auto i: edges)
            {
                adj[i[0]].emplace_back(i[1]);
                adj[i[1]].emplace_back(i[0]);
            }
            queue<pair<int,int>> q;
            vector<int> path(n+1,0);
            q.push({1,0});
           	path[1]=1;
            int ans = INT_MAX,secans=INT_MAX;
            while (!q.empty())
            {
                int node = q.front().first, curr = q.front().second;
                q.pop();
                if (node == n)
                {
                   if(curr<ans)
                   {
                       secans=ans;
                       ans=curr;
                   }
                    if(curr<secans && curr!=ans) secans=curr;
                }
                else
                {
                    for (int next: adj[node])
                    {
                        int pass = curr + time;
                        if ((pass / change) % 2 == 1 && next != n)
                        {
                            pass += (change - (pass % change));
                        }
                        if (path[next]<10)
                        {
                            path[next]++;
                            q.push({next,pass});
                        }
                        else if(next==n) q.push({next,pass});
                    }
                }
            }
            if(secans==INT_MAX || ans==secans)
            {
                if(ans<change || (ans/change)%2==1) ans+=(ans-(ans%change));
                ans+=time;
                if(ans<change || (ans/change)%2==1) ans+=(ans-(ans%change));
                return ans+time;
            }   
            return secans;
        }
};