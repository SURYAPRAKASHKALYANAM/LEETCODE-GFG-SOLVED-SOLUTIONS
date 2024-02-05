class Solution
{
    public:
        int minMutation(string startGene, string endGene, vector<string> &bank) 
        {
            set<string> s(bank.begin(),bank.end());
            char arr[]={'A','C','G','T'};
            int len=8;
            queue<pair<int,string>> q;
            q.push({0,startGene});
            while(!q.empty())
            {
                auto it=q.front();
                int dis=it.first;
                string curr=it.second;
                q.pop();
                if(curr==endGene) return dis;
                for(int i=0;i<8;i++)
                {
                    char org=curr[i];
                    for(int j=0;j<4;j++)
                    {
                        if(curr[i]==arr[j]) continue;
                        curr[i]=arr[j];
                        if(s.count(curr))
                        {
                            s.erase(curr);
                            q.push({dis+1,curr});
                        }
                    }
                    curr[i]=org;
                }
                
            }
            
            return -1;
        }
};