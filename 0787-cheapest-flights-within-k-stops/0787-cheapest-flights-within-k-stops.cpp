class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int source, int destination, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minheap;
        vector<int> dist(n,1e9);
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
        {
            adj[it[0]].emplace_back(make_pair(it[1],it[2]));
        }
        dist[source]=0;
        minheap.push({0,{0,source}});
        int mindis=1e9;
        while(!minheap.empty())
        {
            auto it=minheap.top();
            minheap.pop();
            int steps=it.first;
            int dis=it.second.first,node=it.second.second;
            if(steps<=k+1)
            {
                if(node==destination) mindis=min(mindis,dis);
            }
            if(steps==k+1) continue;
            for(auto next:adj[node])
            {
                int adjwt=next.second;
                int adjnode=next.first;
                if(adjwt+dis < dist[adjnode])
                {
                    dist[adjnode]=adjwt+dis;
                    minheap.push({steps+1,{dist[adjnode],adjnode}});
                }
            }
        }
        return (mindis==1e9)?-1:mindis;
    }
};