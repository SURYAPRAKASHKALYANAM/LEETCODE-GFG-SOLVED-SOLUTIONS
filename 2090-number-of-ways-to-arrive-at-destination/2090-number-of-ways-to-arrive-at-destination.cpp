class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=(1e9+7);
        vector<pair<long long,long long>> adj[n];
        
        for(auto i: roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<long long,long long>, 
        vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0, 0});
        
        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        
        dist[0]=0;
        ways[0]=1;
        
        while(!pq.empty())
        {
            long long distance=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            
            for(auto i: adj[node])
            {
                int adjNode=i.first;
                int weight=i.second;
                
                if(distance+weight < dist[adjNode])
                {
                    dist[adjNode]=distance+weight;
                    
                    pq.push({dist[adjNode], adjNode});
                    
                    ways[adjNode]=ways[node]%mod;
                }
                else if(distance+weight==dist[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        
        return (int)(ways[n-1])%mod;
    }
};