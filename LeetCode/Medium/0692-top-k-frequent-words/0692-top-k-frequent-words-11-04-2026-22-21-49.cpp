class Solution
{
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            vector<string> ans;
            map<int, set < string>> m;
            unordered_map<string, int> counts;
            for (auto i: words) counts[i]++;
            for (auto i: counts)
            {
                m[i.second].insert(i.first);
            }
            for (auto it = m.rbegin(); k != 0; it++)
            {
                for (auto i: it->second)
                {
                    if (k == 0) break;
                    ans.emplace_back(i);
                    k--;
                }
            }
            return ans;
        }
};