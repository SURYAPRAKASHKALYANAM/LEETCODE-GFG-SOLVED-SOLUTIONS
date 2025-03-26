class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> extended;
        for (int i = 0; i < m; i++) {
            extended.insert(extended.end(), grid[i].begin(), grid[i].end());
        }
        int cnt = 0;
        sort(extended.begin(), extended.end());
        int size = m * n;
        int median = ((size & 1) ? size : size - 1) / 2;
        for (auto i : extended) {

            int diff = abs(i - extended[median]);
            if (diff % x == 0)
                cnt += diff / x;
            else
                return -1;
        }
        return cnt;
    }
};