class Solution
{
    public:
        int getLucky(string s, int k)
        {
            string converted = "";
            for (auto i: s) converted += to_string((i - 'a') + 1);
            int res = 0;
            while (k--)
            {
                for (auto i: converted) res += (i - '0');
                converted = to_string(res);
                if (k != 0) res = 0;
            }
            return res;
        }
};