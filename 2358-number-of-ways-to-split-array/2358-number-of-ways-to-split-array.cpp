class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long right_sum = 0, left_sum = 0;
        int cnt = 0;
        for(auto i:nums) right_sum+=i;
        for (int i = 0; i < nums.size() - 1; i++) {
            left_sum += nums[i];
            right_sum -= nums[i];
            if (left_sum >= right_sum)
                cnt++;
        }
        return cnt;
    }
};