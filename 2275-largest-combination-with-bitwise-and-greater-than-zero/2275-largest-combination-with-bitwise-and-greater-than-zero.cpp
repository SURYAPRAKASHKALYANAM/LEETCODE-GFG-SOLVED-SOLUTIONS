class Solution
{
    public:
        int largestCombination(vector<int> &candidates)
        {
            int max_cnt = 0;
            for (int bit = 0; bit <= 24; bit++)
            {
                int cnt = 0;
                for (auto i: candidates)    if (i &(1 << bit)) cnt++;
                max_cnt = max(max_cnt, cnt);
                if (cnt = 0) break;
            }
            return max_cnt;
        }
};