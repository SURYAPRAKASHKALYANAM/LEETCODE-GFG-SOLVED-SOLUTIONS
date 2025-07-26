class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum = 0, len = nums.size();
        int left = 0, right = 0, currSum = 0;
        unordered_map<int, int> seen;
        while (right < len) {
            while (left <= right && seen[nums[right]]) {
                currSum -= nums[left];
                seen[nums[left]]--;
                left++;
            }
            currSum += nums[right];
            maxSum = max(maxSum, currSum);
            seen[nums[right]]++;
            right++;
        }
        return maxSum;
    }
};