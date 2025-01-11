class Solution
{
    public:
        bool canConstruct(string s, int k)
        {
            vector<int> counts(26, 0);
            int len = s.size();
            for (auto i: s) counts[i - 'a']++;
            int odd = 0;
            for (int i: counts) odd += (i & 1);
            return odd <= k && len >= k;
        }
};