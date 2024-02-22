class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0),outdegree(n+1,0);
        for(auto i:trust)
        {
            indegree[i[1]]++;
            outdegree[i[0]]++;
        }
        int judge=-1;
        for(auto i=1;i<=n;i++)
        {
            if(indegree[i]==(n-1) && !outdegree[i]) judge=i;
        }
        
        return judge;
        
    }
};