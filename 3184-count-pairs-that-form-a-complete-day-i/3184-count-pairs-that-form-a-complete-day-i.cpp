class Solution
{
    public:
        int countCompleteDayPairs(vector<int> &hours)
        {
            map<int, vector < int>> m;
            for (auto i = 0; i < hours.size(); i++) m[hours[i] % 24].emplace_back(i);
            int cnt = 0;
            // cnt = (cnt > 0 && cnt <= 2) ? --cnt : cnt;
            for (auto i = 0; i < hours.size(); i++)
            {
                int left=(24-(hours[i]%24))%24;
                if (left>=0)
                {
                    for (auto j: m[left])
                    {
                        if (j > i) cnt++;
                    }
                }
            }
            return cnt;
        }
};