class Solution
{
    public:
        vector<int> missingRolls(vector<int> &rolls, int mean, int n)
        {
            int m = rolls.size();
            int rem = ((n + m) *mean - accumulate(rolls.begin(), rolls.end(), 0)), sum;
            if(rem<=0 || rem<n) return {};
            vector<int> ans(n, 0);
            while (rem>0)
            {
                if (rem <= n)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(ans[i]==6) return {};
                        ans[i]+=(rem-- > 0);
                    }
                }
                else
                {
                    sum = rem / n;
                    rem = rem % n;
                    if (sum > 6 || (sum==6 && rem!=0)) return {};
                    for (int i = 0; i < n; i++) ans[i] += sum;
                }
            }
            return ans;
        }
};