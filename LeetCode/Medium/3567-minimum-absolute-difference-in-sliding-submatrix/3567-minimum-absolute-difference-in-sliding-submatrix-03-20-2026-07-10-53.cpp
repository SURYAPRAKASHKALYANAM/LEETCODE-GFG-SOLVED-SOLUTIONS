class Solution {
public:
    int find(set<int>& nums) {
        auto it = nums.begin();
        int prev = *it, mini = INT_MAX;
        it++;
        while (it != nums.end()) {
            mini = min(mini, abs(prev - *it));
            prev = *it;
            it++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            if ((i + k) <= m)
                ans.push_back({});
            for (int j = 0; j < n; j++) {
                if ((i + k) <= m && (j + k) <= n) {
                    set<int> nums;
                    for (int r = i; r < (i + k); r++) {
                        for (int c = j; c < (j + k); c++)
                            nums.insert(grid[r][c]);
                    }
                    ans.back().push_back(find(nums));
                }
            }
        }
        return ans;
    }
};