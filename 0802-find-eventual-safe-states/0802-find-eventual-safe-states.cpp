class Solution {
public:
    bool dfs(int node,vector<vector<int>> &adj,vector<int> &visited,vector<int> &pathvisited,int check[])
    {
        visited[node]=1;
        pathvisited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                if(dfs(it,adj,visited,pathvisited,check)) return true;
            }
            else if(pathvisited[it]) return true;
        }
        check[node]=1;
        pathvisited[node]=0;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> visited(V,0),pathvisited(V,0);
        int check[V];
        for(int i=0;i<V;i++) check[i]=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,pathvisited,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(check[i])
            {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};