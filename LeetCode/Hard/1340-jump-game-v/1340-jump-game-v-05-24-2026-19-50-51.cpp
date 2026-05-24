class Solution {
public:
    int find(int pos, vector<int>& arr, vector<int>& dp, int d) {
        if (pos < 0 || pos >= arr.size())
            return 0;
        if (dp[pos] != -1)
            return dp[pos];
        int max_d = 0;
        //  forward
        for (int i = pos + 1; i <= (pos + d) && i < arr.size(); i++) {
            if (arr[i] >= arr[pos])
                break;
            max_d = max(max_d, 1 + find(i, arr, dp, d));
        }
        // backward
        for (int i = pos - 1; i >= (pos - d) && i >= 0; i--) {
            if (arr[i] >= arr[pos])
                break;
            max_d = max(max_d, 1 + find(i, arr, dp, d));
        }
        return dp[pos] = max_d;
    }
    int maxJumps(vector<int>& arr, int d) {
        int max_d = 0;
        int len = arr.size();
        vector<int> dp(len, -1);
        for (int i = 0; i < len; i++) {
            max_d = max(max_d, 1+find(i, arr, dp, d));
        }
        return max_d;
    }
};