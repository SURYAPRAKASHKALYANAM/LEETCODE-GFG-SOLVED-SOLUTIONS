class Solution
{
    public:
        int reversedig(int n)
        {
            int sum = 0;
            while (n)
            {
                sum = sum *10 + (n % 10);
                n = n / 10;
            }
            return sum;
        }
    int countDistinctIntegers(vector<int> &nums)
    {
        map<int, int> have;
        int len = 0;
        for (auto i: nums)
        {
            if (have[i] != 1)
            {
                have[i] = 1;
                len++;
            }
        }
        for (auto i: have)
        {
            int rdig = reversedig(i.first);
            if (have.find(rdig) == have.end())
            {
                len++;
                have[rdig] = 1;
            }
        }
        return len;
    }
};