class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double dist[n];
        for(int i=0;i<n;i++) dist[i]=0;
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>> q;
        q.push({1,start_node});
        dist[start_node]=0;
        while(!q.empty())
        {
            auto it=q.top();
            double dis=it.first;
            int node=it.second;
            q.pop();
            for(auto it:adj[node])
            {
                double adjwt=it.second;
                int next=it.first;
                if(dis*adjwt>dist[next])
                {
                    dist[next]=dis*adjwt;
                    q.push({dist[next],next});
                }
            }
        }
        return dist[end_node];
    }
};