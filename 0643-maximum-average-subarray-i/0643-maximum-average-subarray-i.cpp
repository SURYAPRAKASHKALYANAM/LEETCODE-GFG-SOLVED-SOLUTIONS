class Solution
{
    public:
        double findMaxAverage(vector<int> &nums, int k)
        {
            double avg = INT_MIN, sum = 0;
            for (int i = 0; i < k; i++) sum += nums[i];
            avg = max(avg, (double)(sum / k));
            for (int i = 1; i + k <= nums.size(); i++)
            {
                sum -= nums[i - 1];
                sum += nums[i + k - 1];
                avg = max(avg, (double)(sum / k));
            }
            return avg;
        }
};