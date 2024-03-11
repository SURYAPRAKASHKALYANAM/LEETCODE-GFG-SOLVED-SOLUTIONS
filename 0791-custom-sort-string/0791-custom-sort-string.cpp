class Solution
{
    public:
        string customSortString(string order, string s)
        {
            unordered_map<char, int> m;
            for (auto i = 0; i < order.size(); i++) m[order[i]] = i;
            auto compare =[&](char a, char c)
            {
                return m[a] < m[c];
            };
            sort(s.begin(), s.end(), compare);
            return s;
        }
};