class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> graph(n);
        vector<int> ans,indegree(n,0);
        for(auto i:edges)
        {
            graph[i[0]].emplace_back(i[1]);
            graph[i[1]].emplace_back(i[0]);
            indegree[i[0]]++,indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n;i++){
            if(indegree[i]==1) q.push(i), indegree[i]--; 
        } 
        while(!q.empty())
        {
            int n=q.size();
            ans.clear();
            for(int i=0;i<n;i++)
            {
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto child:graph[node])
                {
                    indegree[child]--;
                    if(indegree[child]==1) q.push(child);
                }
            }
        }
        return ans;
    }
};