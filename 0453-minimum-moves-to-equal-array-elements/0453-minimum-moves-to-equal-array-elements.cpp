class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int steps = nums.back() - nums[0], prev = 0;
        int len = nums.size() - 1;
        for (int j = len; j > 0; j--) {
            int dif = nums[j - 1] + steps - (nums[j] + prev);
            if (dif == 0)
                break;
            prev = steps;
            steps += dif;
        }
        return steps;
    }
};