class Solution
{
    public:
        int maxCount(vector<int> &banned, int n, int maxSum)
        {
            unordered_map<int, int> have;
            for (auto i: banned) have[i] = 1;
            int cnt = 0, s = 0;
            for (auto i = 1; i <= n; i++)
            {
                if (!have[i] && s + i <= maxSum) s += i, cnt++;
            }
            return cnt;
        }
};