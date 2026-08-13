class Solution
{
    public:
        int minimumPushes(string word)
        {
            unordered_map<char, int> counts;
            int ans = 0;
            for (auto i: word) counts[i]++;
            priority_queue<pair<int, char>> v;
            int push = 0;
           	for(auto i:counts)     v.push({i.second,i.first});
            while (!v.empty())
            {
                ans++;
                if (ans <= 8)
                {
                    push += v.top().first;
                }
                else if (ans <= 16) push += 2 *v.top().first;
                else if (ans <= 24) push += 3 *v.top().first;
                else push += 4 *v.top().first;
                v.pop();
            }

            return push;
        }
};