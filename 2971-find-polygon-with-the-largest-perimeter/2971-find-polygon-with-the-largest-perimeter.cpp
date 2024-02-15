class Solution
{
    public:
        long long largestPerimeter(vector<int> &nums)
        {
            int n = nums.size();
            vector<long long > pre(n, 0);
            sort(nums.begin(), nums.end());
            pre[0] = nums[0];
            for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + nums[i];
            long long  max_sum = -1;
            for (int i = 2; i < n; i++)
            {
                if (pre[i - 1] > nums[i]) max_sum = pre[i];
            }
            return max_sum;
        }
};