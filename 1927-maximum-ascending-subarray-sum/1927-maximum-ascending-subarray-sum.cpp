class Solution
{
    public:
        int maxAscendingSum(vector<int> &nums)
        {
            int max_sum = nums[0], sum = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    sum += nums[i];
                    max_sum = max(max_sum, sum);
                }
                else max_sum = max(max_sum, sum = nums[i]);;
            }
            return max_sum;
        }
};