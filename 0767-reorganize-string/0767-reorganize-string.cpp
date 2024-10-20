class Solution
{
    public:
        string reorganizeString(string s)
        {
            priority_queue<pair<int, int>> q;
            unordered_map<int, int> m;
            for (char i: s) m[i - 'a']++;
            string ans = "";
            for (auto i: m) q.push({ i.second,i.first });
            char a,b;
            int cnt1=0,cnt2=0;
            while (!q.empty())
            {
                a = ('a' + q.top().second);
                int cnt1 = q.top().first - 1;
                q.pop();
                if(!ans.empty() && ans.back()==a) return "";
                ans += a;
                if (!q.empty())
                {
                    b = ('a' + q.top().second);
                    cnt2 = q.top().first - 1;
                    q.pop();
                    ans += b;
                }
                if (cnt1 > 0) q.push({cnt1,a-'a'});
                if (cnt2 > 0) q.push({cnt2,b-'a'});
            }
            return ans.size() != s.size() ? "" : ans;
        }
};