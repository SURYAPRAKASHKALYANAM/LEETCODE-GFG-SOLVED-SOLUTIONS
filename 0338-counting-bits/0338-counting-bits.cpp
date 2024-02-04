class Solution
{
    public:
        vector<int> countBits(int n)
        {
            vector<int> ans(n + 1);
            ans[0] = 0;
            if(n==0) return ans;
            ans[1] = 1;
            int lastpow = 1, diff;
            for (int i = 2; i <= n; i++)
            {
               	// optimal : ans[i]=ans[i>>1]+(i%2);
                if ((i &(i - 1)) == 0)
                {
                    lastpow = i;
                    ans[i] = 1;
                    continue;
                }
                diff = i - lastpow;
                ans[i] = ans[diff] + 1;
            }
            return ans;
        }
};