class Solution
{
    public:
        bool closeStrings(string word1, string word2)
        {
            if (word1.size() != word2.size()) return false;
            unordered_map<char, int> m1, m2;
            unordered_map<int, int> n;
            for (auto i: word1) m1[i]++;
            for (auto i: word2)
            {
                m2[i]++;
                if(m1[i]==0) return false;
            }
            for (auto i: m1) n[i.second]++;
            for (auto i: m2) n[i.second]--;
            for (auto i: n)
            {
                if (i.second != 0) return 0;
            }
            return 1;
        }
};