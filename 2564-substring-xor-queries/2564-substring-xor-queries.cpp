class Solution
{
public:
    vector<std::vector<int>> substringXorQueries(std::string s, std::vector<std::vector<int>> &queries)
    {
        unordered_map<int, std::pair<int, int>> xorMap;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            int currentXor = 0;
            for (int j = i; j < n && j - i < 32; ++j) // Limit length to prevent large integers
            {
                currentXor = (currentXor << 1) + (s[j] - '0');
                if (!xorMap.count(currentXor))
                {
                    xorMap[currentXor] = {i, j};
                }
                if (s[i] == '0')
                break;
            }
        }

        vector<vector<int>> ans;
        for (auto &query : queries)
        {
            int target = query[0] ^ query[1];
            if (xorMap.count(target))
            {
                ans.push_back({xorMap[target].first, xorMap[target].second});
            }
            else
            {
                ans.push_back({-1, -1});
            }
        }

        return ans;
    }
};
