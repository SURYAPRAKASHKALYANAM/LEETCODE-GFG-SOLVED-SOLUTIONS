class Solution {
public:
    int singleNumber(vector<int>& nums) {
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
    }
};