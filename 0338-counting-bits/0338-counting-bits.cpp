class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int lastPow = 1;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                lastPow = i;
                ans[i] = 1;
            } else {
                ans[i] = ans[lastPow] + ans[i % lastPow];
            }
        }
        return ans;
    }
};