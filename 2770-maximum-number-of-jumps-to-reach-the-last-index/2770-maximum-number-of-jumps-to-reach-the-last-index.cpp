class Solution {
public:
    int find(int pos, vector<int>& nums, vector<int> adj[], vector<int>& dp) {
        if (pos >= nums.size())
            return 0;
        if (dp[pos] != INT_MIN)
            return dp[pos];
        if (adj[pos].size() == 0)
            return (pos == nums.size() - 1) ? 0 : -1;
        int max_d = INT_MIN;
        for (int next : adj[pos]) {
            int dis = find(next, nums, adj, dp);
            if (dis != -1) {
                max_d = max(max_d, 1 + dis);
            }
        }
        return dp[pos] = (max_d == INT_MIN ? -1 : max_d);
    }
    int maximumJumps(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> adj[len];
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[j] >= 1LL * nums[i] - 1LL * target &&
                    1LL * nums[j] <= 1LL * nums[i] + 1LL * target) {
                    adj[i].emplace_back(j);
                }
            }
            cout << endl;
        }
        vector<int> dp(len, INT_MIN);
        return find(0, nums, adj, dp);
    }
};