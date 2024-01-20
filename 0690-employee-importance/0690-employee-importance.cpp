/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size();
        unordered_map<int,int> importance;
        vector<int> adj[2001];
        int visited[2001];
        for(int i=0;i<n;i++)
        {
            auto ii=employees[i];
            visited[ii->id]=0;
            importance[ii->id]=ii->importance;
            for(auto next : ii->subordinates)
            {
                adj[ii->id].emplace_back(next);
            }
        }
        int tot=0;
        queue<int> q;
        q.push(id);
        visited[id]=1;
        while(!q.empty())
        {
            auto curr=q.front();
            tot+=importance[curr];
            q.pop();
            for(auto next:adj[curr])
            {
               if(!visited[next]) 
               {
                   visited[next]=1;
                   q.push(next);
               }
            }
        }
        return tot;
    }
};