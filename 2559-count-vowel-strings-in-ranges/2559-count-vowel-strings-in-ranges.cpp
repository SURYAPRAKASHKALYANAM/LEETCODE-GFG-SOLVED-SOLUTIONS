class Solution
{
    public:
        bool isvowel(char c)
        {
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
        }
    vector<int> vowelStrings(vector<string> &words, vector<vector< int>> &queries)
    {
        vector<int> v(words.size(), 0), ans;
        int prefix=0;
        for (auto i = 0; i < words.size(); i++)
        {
            if (isvowel(words[i].back()) && isvowel(words[i][0]))
            {
                prefix++;
                v[i] = prefix;
            }
            else v[i]=prefix;
        }
        for (auto i: queries)
        {
            if(!i[0]) ans.emplace_back(v[i[1]]);
            else ans.emplace_back(v[i[1]]-v[i[0]-1]);
            
        }
        return ans;
    }
};