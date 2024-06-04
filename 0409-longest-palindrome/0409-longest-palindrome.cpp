class Solution
{
    public:
        int longestPalindrome(string s)
        {
            map<int, int> m;
            int max_len = 0, odd_len = 0, f = 0;
            for (auto i: s) m[i - 'A']++;
            for (auto i: m)
            {
                if (i.second &1) f++, max_len += i.second - 1;
                else max_len += i.second;
            }
            return f ? max_len + 1 : max_len;
        }
};