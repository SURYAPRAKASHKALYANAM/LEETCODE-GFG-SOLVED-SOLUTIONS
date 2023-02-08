class Solution
{
    public:
        int singleNumber(vector<int> &nums)
        {
            long long res = 0;
            for (int i = 0; i < 32; i++)
            {
                int p = 0;
                for (int j = 0; j < nums.size(); j++)
                {
                    int k = abs(nums[j]);
                    if (k &(1 << i)) p++;
                }
                p = p % 3;
                res += pow(2, i) *p;
            }
            int c = 0;
            for (auto i: nums)
            {
                if (i == res) c++;
            }
            return (c == 1) ? res : -res;
        }
};