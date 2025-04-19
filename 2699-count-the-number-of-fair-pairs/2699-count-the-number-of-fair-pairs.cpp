class Solution
{
    public:
    long long countPairs(vector<int> &nums, int target)
    {
        long long res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++)
        {
            while (i < j && nums[i] + nums[j] >= target) j--;
            res += (j - i);
        }
        return res;
    }
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(),nums.end());
        return countPairs(nums, upper + 1) - countPairs(nums, lower);
    }
};