class Compare {
public:
    bool operator()(pair<int,int> p1,pair<int,int>p2)
        {
            return p1.first==p2.first ? p1.second<p2.second : p1.first>p2.first;
        }
};

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long sum=0;
        long d=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> q;
        for(int i=0;i<values.size();i++)
        {
            for(int j=0;j<values[0].size();j++)
            {
                q.push({values[i][j],j});
            }
        }
        while(!q.empty())
        {
            sum+=(q.top().first)*d++;
            q.pop();
        }
        return sum;
    }
};