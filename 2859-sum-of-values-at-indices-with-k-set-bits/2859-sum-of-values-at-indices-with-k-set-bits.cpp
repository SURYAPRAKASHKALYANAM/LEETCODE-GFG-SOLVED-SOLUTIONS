class Solution
{
    public:
        int sumIndicesWithKSetBits(vector<int> &nums, int k)
        {
            if (!k) return nums[0];
            int sum = 0;
            for (int i = 1; i < nums.size(); i++)
                if (__builtin_popcount(i) == k) sum += nums[i];
            return sum;
        }
};