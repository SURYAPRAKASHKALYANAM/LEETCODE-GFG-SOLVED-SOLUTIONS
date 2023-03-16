class Solution
{
    public:
        int minPartitions(string s)
        {
            int ans = 0;
            for (auto i = 0; i < s.size(); i++)
            {
                ans=max(ans,s[i]-'0');
            }
            return ans;
        }
};