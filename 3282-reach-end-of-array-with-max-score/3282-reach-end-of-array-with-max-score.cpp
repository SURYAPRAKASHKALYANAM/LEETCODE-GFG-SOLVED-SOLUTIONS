class Solution
{
    public:
        long long findMaximumScore(vector<int> &nums)
        {
            long long ans = 0;
            long long left = 0, right = 1;
            while (right < nums.size())
            {
                while (right < nums.size() && nums[right] < nums[left]) right++;
                ans += (((right == nums.size()) ? right - 1 : right) - left) *(1L*nums[left]);
                left = right;
                right++;
            }
            return ans;
        }
};