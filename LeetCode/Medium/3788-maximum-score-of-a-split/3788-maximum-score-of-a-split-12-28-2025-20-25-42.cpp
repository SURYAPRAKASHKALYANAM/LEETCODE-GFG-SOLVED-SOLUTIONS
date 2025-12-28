class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int len = nums.size();
        vector<int> suff(len);
        suff[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--)
            suff[i] = min(suff[i + 1], nums[i + 1]);
        long long sum = 0, max_score = INT_MIN;
        for (int i = 0; i < len - 1; i++) {
            sum += nums[i];
            max_score = max(max_score, sum - suff[i]);
        }
        return max_score;
    }
};