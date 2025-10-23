class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int> q;
        int n = grid.size(), m = grid[0].size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sort(grid[i].begin(), grid[i].end(), greater<int>());
            int cnt = limits[i];
            while (cnt) {
                q.push(grid[i][limits[i] - cnt]);
                cnt--;
            }
        }
        while (k--) {
            sum += q.top();
            q.pop();
        }
        return sum;
    }
};