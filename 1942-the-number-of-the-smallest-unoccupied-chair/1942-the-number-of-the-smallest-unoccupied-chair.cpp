class Solution
{
    public:
    set<int> chairs;
    int c=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> occupied;
    int mark(int st, int et)
    {
        int cs;
        while(!occupied.empty() && occupied.top().first<=st)
        {
            chairs.insert(occupied.top().second);
            occupied.pop();
        }
        if(chairs.empty())
        {
            occupied.push({et,c});
            cs=c++;
        }
        else
        {
            cs=*chairs.begin();
            occupied.push({et,cs});
            chairs.erase(cs);
        }
        return cs;
        
    }
    int smallestChair(vector<vector < int>> &times, int targetFriend)
    {
        priority_queue<int> q;
        int pos = 0;
        int  order=times[targetFriend][0];
        sort(times.begin(), times.end());
        for (auto i:times)
        {
            int intime = i[0], outtime = i[1];
            pos = mark(intime, outtime);
            if (order == intime) break;
        }
        return pos;
    }
};