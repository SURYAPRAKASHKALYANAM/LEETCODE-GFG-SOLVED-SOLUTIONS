class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n],indegree(n,0);
        vector<set<int>> ans(n);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(!indegree[i]) q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto next:adj[node])
            {
                ans[next].insert(node);
                ans[next].insert(ans[node].begin(),ans[node].end());
                indegree[next]--;
                if(!indegree[next]) q.push(next);
            }
        }
        vector<vector<int>> final_ans(n);
        for(int i=0;i<ans.size();i++)
        {
            for(auto ele:ans[i]) final_ans[i].emplace_back(ele);
        }
        return final_ans;
    }
};