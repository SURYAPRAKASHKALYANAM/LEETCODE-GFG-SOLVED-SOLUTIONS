class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long cnt = 0;
        int curr = 0, max_ele = *max_element(nums.begin(), nums.end());
        int start = 0, end = 0, n = nums.size();
        while (end < n) {
            while (curr < k && end < n) {
                if (nums[end] == max_ele)
                    curr++;
                end++;
            }
            while (curr == k && start <= end) {
                cnt += (n - end) + 1;
                if (nums[start] == max_ele)
                    curr--;
                start++;
            }
        }
        return cnt;
    }
};