class Solution {
public:
    int helper(vector<int>& nums, int div) {
        int sum = 0;
        for (int i : nums)
            sum += (i / div) + (i % div ? 1 : 0);
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1, end = *max_element(begin(nums), nums.end());
        int mid, ans = end;
        while (start <= end) {
            mid = start + (end - start) / 2;
            int val = helper(nums, mid);
            if (val <= threshold) {
                ans = min(ans, mid);
                end = mid - 1;
            } else
                start = mid + 1;
        }
        return ans;
    }
};