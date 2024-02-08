class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,long > m;
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i]]+=i;
        }
        long long max_score=-1;
        int ans=-1;
        for(auto i:m)
        {
            if(i.second>max_score)
            {
                max_score=i.second;
                ans=i.first;
            }
            else if(i.second==max_score)
            {
                ans=min(ans,i.first);
            }
        }
        return ans;
    }
};