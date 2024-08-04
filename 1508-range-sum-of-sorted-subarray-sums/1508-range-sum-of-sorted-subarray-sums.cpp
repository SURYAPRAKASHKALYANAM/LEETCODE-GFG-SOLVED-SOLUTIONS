class Solution
{
    public:
        int rangeSum(vector<int> &nums, int n, int left, int right)
        {
            int ans = 0, start = 0, end = 0, sum;
            vector<int> result;
            while (start < n)
            {
                sum = 0;
                end = start;
                while (end < n)
                {
                    sum += nums[end++];
                    result.emplace_back(sum);
                }
                start++;
            }
            sort(result.begin(), result.end());
            int mod = 1e9 + 7;
            for (int i = left - 1; i <= (right - 1); i++) ans = (ans + result[i]) % mod;
            return ans;
        }
};