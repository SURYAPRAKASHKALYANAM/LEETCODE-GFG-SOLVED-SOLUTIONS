class Solution
{
    public:
        string stringHash(string s, int k)
        {
            int n = s.size(), i = 0, step = k;
            string ans = "";
            while (i < n)
            {
                int sum = 0;
                while (step--) sum += (s[i++] - 'a');
                sum %= 26;
                ans += ('a' + sum);
                step = k;
            }
            return ans;
        }
};