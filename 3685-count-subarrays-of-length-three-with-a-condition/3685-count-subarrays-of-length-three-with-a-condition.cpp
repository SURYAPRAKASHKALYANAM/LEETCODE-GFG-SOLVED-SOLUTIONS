class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        for (int i = 2; i < nums.size(); i++) {
            if ((nums[i - 2] + nums[i]) == (nums[i - 1] / 2) && (nums[i-1]%2)==0)
                cnt++;
        }
        return cnt;
    }
};