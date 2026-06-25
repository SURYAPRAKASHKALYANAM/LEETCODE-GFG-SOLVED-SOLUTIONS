class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int len = nums.size();
        int cnt = 0, freq, sub_len;
        for (int i = 0; i < len; i++) {
            freq = sub_len = 0;
            for (int j = i; j < len; j++) {
                freq += (nums[j] == target);
                sub_len++;
                if (freq > (sub_len / 2))
                    cnt++;
            }
        }
        return cnt;
    }
};