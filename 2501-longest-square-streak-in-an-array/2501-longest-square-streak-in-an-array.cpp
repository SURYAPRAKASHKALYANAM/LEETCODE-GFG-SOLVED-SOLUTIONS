class Solution
{
    public:
        int longestSquareStreak(vector<int> &nums)
        {
            map<long long, int> visited, have;
            sort(nums.begin(), nums.end());
            int max_len = -1;
            for (int i: nums) have[i] = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                long long ele = nums[i];
                if (!visited[ele])
                {
                    int cnt = 0;
                    while (have[ele] && !visited[ele])
                    {
                        visited[ele] = 1;
                        ele *= ele;
                        cnt++;
                    }
                    if (cnt > 1) max_len = max(cnt, max_len);
                }
            }
            return max_len;
        }
};