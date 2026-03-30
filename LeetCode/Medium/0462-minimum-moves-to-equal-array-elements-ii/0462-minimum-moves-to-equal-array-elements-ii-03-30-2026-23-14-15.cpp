class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int mid;
        // if (len & 1)
            mid = nums[len / 2]; // this case alone work too
        // else
        //     mid = (nums[len / 2] + nums[(len / 2) - 1]) / 2;
        int movs = 0;
        for (int i : nums)
            movs += abs(mid - i);
        return movs;
    }
};