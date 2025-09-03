class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        O (32*N);
        int bit = 1;
        int ans = 0;
        int cnt;
        for (int i = 0; i < 32; i++) {
            cnt = 0;
            for (auto num : nums) {
                if (num & bit)
                    cnt++;
            }
            if (cnt % 3)
                ans |= bit;
            bit <<= 1;
        }
        return ans;
        */
        /* O NLogN */
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i += 3) {
            if (nums[i] != nums[i + 1] && nums[i] != nums[i + 2])
                return nums[i];
        }
        return nums[len - 1];
    }
};