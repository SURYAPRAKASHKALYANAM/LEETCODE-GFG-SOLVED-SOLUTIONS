class Solution
{
    public:
        vector<int> singleNumber(vector<int> &nums)
        {
            long int n1 = 0, n2 = 0, val = 0;
            for (auto i: nums) val ^= i;
            val &= -val;
            for (auto i: nums)
            {
                if (val&i) n1 ^= i;
                else n2 ^= i;
            }
            return {(int)n1,(int)n2};
        }
};