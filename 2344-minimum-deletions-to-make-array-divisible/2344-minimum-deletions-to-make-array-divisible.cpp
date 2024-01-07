class Solution
{
    public:
        int minOperations(vector<int> &nums, vector<int> &numsDivide)
        {
            int gcd = numsDivide[0];
            for (int i = 1; i < numsDivide.size(); i++)
            {
                gcd = __gcd(gcd, numsDivide[i]);
            }
            sort(nums.begin(), nums.end());
            int i = 0;
            while (i < nums.size() && gcd % nums[i] != 0)
            {
                if(nums[i]>gcd) return -1;
                i++;
            }

            return (i == nums.size()) ? -1 : i;
        }
};