class Solution
{
    public:
        int numberOfBeams(vector<string> &bank)
        {
            int ans = 0;
            vector<int> counts;
            map<string, int> m;
            for (auto i: bank)
            {
                if (m[i] == 0)
                {
                    m[i] = count(i.begin(), i.end(), '1');
                    if (m[i] != 0)
                        counts.emplace_back(m[i]);
                }
                else counts.emplace_back(m[i]);
            }
            for (int i = 1; i < counts.size(); i++)
            {
                ans += (counts[i - 1] *counts[i]);
            }
            return ans;
            
            //OPTIMAL SOLUTION SPACE O(1)
            // int res=0,prev=0,cnt;
            // for(auto i:bank)
            // {
            //     cnt=count(begin(i),end(i),'1');
            //     if(cnt)
            //     {
            //         res+=prev*cnt;
            //         prev=cnt;
            //     }
            // }
            // return res;
        }
};