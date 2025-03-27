class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ele = nums[0], cnt = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == ele) {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }
        }
        cnt = 0;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele) {
                ans[i] = ++cnt;
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] * 2 > (i + 1) && (cnt - ans[i]) * 2 > (n - i - 1)) {
                return i;
            }
        }
        return -1;
    }
};