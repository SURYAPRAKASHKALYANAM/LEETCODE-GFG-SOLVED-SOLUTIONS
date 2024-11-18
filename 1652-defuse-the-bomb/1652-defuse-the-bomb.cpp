class Solution
{
    public:
        vector<int> decrypt(vector<int> &code, int k)
        {
            int n = code.size();
            vector<int> ans(n, 0);
            if (k == 0) return ans;
            vector<int> pref(n, 0);
            pref[0] = code[0];
            for (int i = 1; i < n; i++) pref[i] += pref[i - 1] + code[i];
            if (k > 0)
            {
                for (int i = 0; i < n; i++)
                {
                    int post = i + k, s = 0;
                    if (post >= n)
                    {
                        s += pref[post - n];
                        ans[i] = pref[n - 1] - pref[i] + s;
                    }
                    else ans[i] = pref[post] - pref[i];
                }
                return ans;
            }
            for (int i = 0; i < n; i++)
            {
                int end = i + k, s = 0;
                if (end <= 0)
                {
                    s = pref[n - 1] - pref[n - 1 + end];
                    ans[i] = pref[i] + s - code[i];
                }
                else ans[i] = pref[i] - pref[end - 1] - code[i];
            }
            return ans;
        }
};