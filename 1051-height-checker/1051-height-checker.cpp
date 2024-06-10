class Solution
{
    public:
        int heightChecker(vector<int> &heights)
        {
            int cnt = 0;
            vector<int> nums(heights);
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++)
                if (nums[i] != heights[i]) cnt++;
            return cnt;
        }
};