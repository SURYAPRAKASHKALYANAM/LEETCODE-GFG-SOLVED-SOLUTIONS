class Solution
{
    public:
        int prefixCount(vector<string> &words, string pref)
        {
            int cnt = 0;
            for (auto i: words)
            {
                int curr = 0;
                while (curr < pref.size() && pref[curr] == i[curr]) curr++;
                if (curr == pref.size()) cnt++;
            }
            return cnt;
        }
};