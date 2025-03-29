class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int sum = 0, cnt = 0, left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] + nums[right]) > k)
                right--;
            else if ((nums[left] + nums[right]) < k)
                left++;
            else {
                left++;
                right--;
                cnt++;
            }
        }
        return cnt;
    }
};