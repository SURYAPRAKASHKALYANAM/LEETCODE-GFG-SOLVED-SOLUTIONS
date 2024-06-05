class Solution
{
    public:
        vector<string> commonChars(vector<string> &words)
        {
            vector<string> ans;
            int coun = INT_MAX, bf = 0;
            for (auto i = 'a'; i <= 'z'; i++)
            {
                for (auto ii: words)
                {
                    int r = count(ii.begin(), ii.end(), i);
                    if (r == 0)
                    {
                        bf = 1;
                        break;
                    }
                    coun = min(coun, r);
                }
                if (bf == 1)
                {
                    bf = 0;
                    continue;
                }
                if (coun != INT_MAX)
                {
                    while (coun--) ans.emplace_back(string(1, i));
                }
                coun = INT_MAX;
            }
            return ans;
        }
};