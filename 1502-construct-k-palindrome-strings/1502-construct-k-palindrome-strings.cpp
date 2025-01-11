class Solution
{
    public:
        bool canConstruct(string s, int k)
        {
            vector<int> counts(26, 0);
            int len = s.size();
            for (auto i: s) counts[i - 'a']++;
            int odd = 0, even = 0;
            for (int i: counts)(i & 1) ? odd++ : even++;
            return odd <= k && len >= k;
        }
};