class Solution {
public:
    void add(string& ans,int cnt,char c)
    {
        while(cnt--) ans+=c;
    }
    string repeatLimitedString(string s, int repeatLimit) {
        string ans="";
        priority_queue<pair<char,int>> q;
        unordered_map<int,int> m;
        for(auto i:s) m[i]++;
        for(auto i:m) q.push({i.first,i.second});
        while(!q.empty())
        {
            auto i=q.top();q.pop();
            if(i.second>repeatLimit)
            {
                add(ans,repeatLimit,(i.first));
                if(q.empty()) break;
                auto next=q.top();q.pop();
                if(next.second-1) q.push({next.first,next.second-1});
                ans+=next.first;
                q.push({i.first,i.second-repeatLimit});
            }
            else add(ans,i.second,(i.first));;
        }
        return ans;
    }
};