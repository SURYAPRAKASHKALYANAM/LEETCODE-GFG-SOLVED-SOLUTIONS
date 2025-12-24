class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int prev = 0, lastPrev = -1, curr;
        curr = prev = nums[0];
        for (int i = 1; i < len; i++) {
            if (lastPrev != -1)
                curr = max(lastPrev + nums[i], prev);
            else
                curr = max(prev, nums[i]);
            lastPrev = prev;
            prev = curr;
        }
        return prev;
    }
};