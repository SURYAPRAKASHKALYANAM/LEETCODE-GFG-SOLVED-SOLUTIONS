class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        if(costs.size()==1) return costs[0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        int beg=0,end=costs.size()-1;
        int first=candidates;
        while(first-- && beg<end)
        {
            q.push({costs[beg],beg++});
            q.push({costs[end],end--});
            
        }
        long long ans=0;
        while(k && !q.empty())
        {
            int ind=q.top().second;
            ans+=q.top().first;
            q.pop();
            if(ind<beg && beg<end)
            {
               q.push({costs[beg],beg++}); 
            }
            else if(end>0 && end>=beg) q.push({costs[end],end--});
            k--;
        }
        return ans;
    }
};