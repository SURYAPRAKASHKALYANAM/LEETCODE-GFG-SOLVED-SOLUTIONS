class Solution
{
    public:
        int minSteps(string s, string t)
        {
            map<char, int> m;
            for (auto i = 0; i < s.size(); i++)
            {
                m[t[i]]++;
                m[s[i]]--;
            }
            int k = 0;
            for (auto i: t)
            {
                if (m[i] > 0)
                {
                    k++;
                    m[i]--;
                }
            }
            return k;
        }
};