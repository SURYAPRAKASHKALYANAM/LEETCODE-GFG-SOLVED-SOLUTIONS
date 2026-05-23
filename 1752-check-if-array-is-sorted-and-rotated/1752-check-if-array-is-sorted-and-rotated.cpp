class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n - 1; i++)
            cnt += nums[i + 1] < nums[i];
        cnt += nums[n - 1] > nums[0];
        return cnt <= 1;
    }
};