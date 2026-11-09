class Solution
{
    public:
        long long maximumSubarraySum(vector<int> &nums, int k)
        {
            long long max_sum = 0, sum = 0;
            unordered_map<int, int> m;
            int curr = 0, start = 0, end = 0, n = nums.size();
            for (; end < n; end++)
            {
                m[nums[end]]++;
                if (m[nums[end]] == 1) curr++, sum += nums[end];
                if (end - start == k)
                {
                    if (m[nums[start]] == 1)
                    {
                        m[nums[start]]--;
                        curr--;
                        sum -= nums[start++];
                    }
                    else m[nums[start]]--, start++;
                }
                if (curr == k) max_sum = max(max_sum, sum);
            }
            return max_sum;
        }
};