class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        vector<int> ans;
        unordered_map<int,int> m,visited;
        int c=0;
        for(auto j=0;j<A.size();j++) m[A[j]]=j;
        for(auto j=0;j<B.size();j++)
        {
            if(j>=m[B[j]]) c++;
            if(visited[A[j]]) c++;
            visited[B[j]]++;
            ans.emplace_back(c);
        }
        return ans;
        
    }
};