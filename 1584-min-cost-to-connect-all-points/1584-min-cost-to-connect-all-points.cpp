class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }
        int sum=0;
        vector<int> visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> min_heap;
        min_heap.push({0,0});
        while(!min_heap.empty())
        {
            auto it=min_heap.top();
            min_heap.pop();
            int dis=it.first;
            int node=it.second;
            if(visited[node]) continue;
            visited[node]=1;
            sum+=dis;
            for(auto i:adj[node])
            {
                int next=i.first;
                int wt=i.second;
                if(!visited[next]) min_heap.push({wt,next});
            }
        }
        return sum;
    }
};