class Solution
{
    public:
        long long maximumSubarraySum(vector<int> &nums, int k)
        {
            long long c = 0, sum = 0, maxi = 0;
            map<int, int> m;
            for (int i = 0; i < k; i++)
            {
                if (!m[nums[i]]) c++;
                m[nums[i]]++;
                sum += nums[i];
            }
            if (c == k) maxi = max(maxi, sum);
            for (int i = 1; i + k <= nums.size(); i++)
            {
                m[nums[i - 1]]--;
                if (!m[nums[i - 1]]) c--;
                sum -= nums[i - 1];
                if (!m[nums[i + k - 1]]) c++;
                m[nums[i + k - 1]]++;
                sum += nums[i + k - 1];
                if (c == k) maxi = max(maxi, sum);
            }
            return maxi;
        }
};