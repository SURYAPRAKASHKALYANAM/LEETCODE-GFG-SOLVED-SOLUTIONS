class Solution
{
    public:
        int minOperations(vector<int> &nums)
        {
            map<int, int> m;
            for (auto i: nums) m[i]++;
            int cnt = 0, k;
            for (auto i: m)
            {
                k = i.second;
                if (k == 1) return -1;
                if (k % 3 == 0) cnt += (k / 3);
                else if (k % 3 == 1 || k % 3 == 2)
                {
                    cnt += (k / 3) + 1;
                }
            }
            return cnt;
        }
};