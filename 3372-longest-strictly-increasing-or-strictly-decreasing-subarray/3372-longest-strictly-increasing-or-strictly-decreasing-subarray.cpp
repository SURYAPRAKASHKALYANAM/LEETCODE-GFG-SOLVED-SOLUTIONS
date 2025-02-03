class Solution
{
    public:
        int longestMonotonicSubarray(vector<int> &nums)
        {
            int max_len = 1, n = nums.size(),cnt2=1,cnt1 = 1;
            for (int i = 1; i < n; i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    cnt1++;
                    max_len = max(max_len, cnt1);
                }
                else cnt1 = 1;
                if (nums[i] < nums[i - 1])
                {
                    cnt2++;
                    max_len = max(max_len, cnt2);
                }
                else cnt2 = 1;
            }
            return max_len;
        }
};