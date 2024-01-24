class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& dict) {
        unordered_set<string> pres(dict.begin(),dict.end());
        queue<pair<string,int>> q;
        q.push(make_pair(begin,1));
        pres.erase(begin);
        while(!q.empty())
        {
            auto curr=q.front().first;
            int level=q.front().second;
            q.pop();
            if(curr==end) return level;
            for(int i=0;i<curr.size();i++)
            {
                char original=curr[i];
                for(char c='a';c<='z';c++)
                {
                    curr[i]=c;
                    if(pres.find(curr)!=pres.end())
                    {
                        pres.erase(curr);
                        q.push(make_pair(curr,level+1));
                    }
                }
                curr[i]=original;
            }
        }
        return 0;
    }
};