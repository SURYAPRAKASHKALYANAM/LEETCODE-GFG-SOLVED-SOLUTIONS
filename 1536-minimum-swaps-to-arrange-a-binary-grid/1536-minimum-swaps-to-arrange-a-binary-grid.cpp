class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 0;
        auto findZeros = [&](int row) {
            int req = n - row - 1;
            for (int r = row; r < n; r++) {
                bool notFound = false;
                for (int j = row + 1; j < n; j++) {
                    if (grid[r][j] == 1) {
                        notFound = true;
                        break;
                    }
                }
                if (!notFound)
                    return r;
            }
            return -1;
        };
        for (int i = 0; i < n; i++) {
            int idx = findZeros(i);
            if (idx == -1)
                return -1;
            for (int r = idx - 1; r >= i; r--) {
                swap(grid[r], grid[r + 1]);
            }
            cnt += (idx - i);
        }
        return cnt;
    }
};