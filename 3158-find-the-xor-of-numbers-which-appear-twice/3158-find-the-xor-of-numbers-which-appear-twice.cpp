class Solution
{
    public:
        int duplicateNumbersXOR(vector<int> &nums)
        {
            unordered_map<int, int> m;
            int ans = -1;
            for (auto i: nums) m[i]++;
            for (auto i: m)
            {
                if (i.second == 2)
                {
                    if (ans == -1) ans = i.first;
                    else ans ^= i.first;
                }
            }
            return ans == -1 ? 0 : ans;
        }
};