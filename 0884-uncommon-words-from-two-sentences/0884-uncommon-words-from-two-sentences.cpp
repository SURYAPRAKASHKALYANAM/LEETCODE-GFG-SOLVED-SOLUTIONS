class Solution
{
    public:
        vector<string> uncommonFromSentences(string s1, string s2)
        {
            unordered_map<string, int> m;
            vector<string> ans;
            stringstream ss1(s1), ss2(s2);
            string token;
            while (getline(ss1, token, ' ')) m[token]++;
            while (getline(ss2, token, ' ')) m[token]++;
            for (auto i: m)
            {
                if (i.second == 1) ans.emplace_back(i.first);
            }
            return ans;
        }
};