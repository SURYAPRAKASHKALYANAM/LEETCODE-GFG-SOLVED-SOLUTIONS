class Solution
{
    public:
        int find(int i, int sum, int x, vector<int> &nums)
        {
            if (i == nums.size()) return x;
            return find(i + 1, sum + (x ^ nums[i]), x ^ nums[i], nums) + find(i + 1, sum, x, nums);
        }
    int subsetXORSum(vector<int> &nums)
    {
        return find(0, 0, 0, nums);
    }
};