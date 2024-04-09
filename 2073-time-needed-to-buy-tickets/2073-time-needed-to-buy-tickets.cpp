class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int cnt=0;
        for(int i=0;i<tickets.size();i++)
        {
            if(tickets[i]>=tickets[k] && i<=k)
            {
                cnt+=tickets[k];
            }
            else if(tickets[i]>=tickets[k]) cnt+=tickets[k]-1;
            else cnt+=tickets[i];
        }
        return cnt;
    }
};