class Solution
{
    public:
        string frequencySort(string s)
        {
            map<char,int> m;
            for(auto i:s) m[i]++;
            priority_queue<pair<int,char>,vector<pair<int,char>>> q;
            for(auto i:m) q.push({i.second,i.first});
            string ans="";
            while(!q.empty())
            {
                auto it=q.top();
                char c=it.second;
                int cnt=it.first;
                q.pop();
                while(cnt--) ans+=c;
            }
            return ans;
        }
};