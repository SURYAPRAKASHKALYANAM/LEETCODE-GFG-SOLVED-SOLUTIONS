class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total_sum = 0;
        unordered_map<long long, int> total_map;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                total_sum += grid[r][c];
                total_map[grid[r][c]]++;
            }
        }
        
        long long top_sum = 0;
        unordered_map<long long, int> top_map;
        unordered_map<long long, int> bottom_map = total_map;
        
        for (int i = 0; i < m - 1; ++i) {
            for (int c = 0; c < n; ++c) {
                long long val = grid[i][c];
                top_sum += val;
                top_map[val]++;
                
                bottom_map[val]--;
                if (bottom_map[val] == 0) bottom_map.erase(val);
            }
            
            long long bottom_sum = total_sum - top_sum;
            long long diff = abs(top_sum - bottom_sum);
            
            if (diff == 0) return true; 
            
            int R1 = i + 1, C1 = n;
            int R2 = m - 1 - i, C2 = n;
            
            if (top_sum > bottom_sum) {
                if (isValidRemoval(R1, C1, diff, top_map, grid, 0, i, 0, n - 1)) return true;
            } else {
                if (isValidRemoval(R2, C2, diff, bottom_map, grid, i + 1, m - 1, 0, n - 1)) return true;
            }
        }
        
        long long left_sum = 0;
        unordered_map<long long, int> left_map;
        unordered_map<long long, int> right_map = total_map;
        
        for (int j = 0; j < n - 1; ++j) {
            for (int r = 0; r < m; ++r) {
                long long val = grid[r][j];
                left_sum += val;
                left_map[val]++;
                
                right_map[val]--;
                if (right_map[val] == 0) right_map.erase(val);
            }
            
            long long right_sum = total_sum - left_sum;
            long long diff = abs(left_sum - right_sum);
            
            if (diff == 0) return true; 
            
            int R1 = m, C1 = j + 1;
            int R2 = m, C2 = n - 1 - j;
            
            if (left_sum > right_sum) {
                if (isValidRemoval(R1, C1, diff, left_map, grid, 0, m - 1, 0, j)) return true;
            } else {
                if (isValidRemoval(R2, C2, diff, right_map, grid, 0, m - 1, j + 1, n - 1)) return true;
            }
        }
        
        return false;
    }

private:
    bool isValidRemoval(int R, int C, long long diff, unordered_map<long long, int>& count_map, 
                        const vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        
        if (R == 1 && C == 1) return false;
        
        if (R >= 2 && C >= 2) {
            return count_map.count(diff) && count_map.at(diff) > 0;
        }
        
        if (R == 1) { 
            return grid[r1][c1] == diff || grid[r1][c2] == diff;
        }
        
        if (C == 1) { 
            return grid[r1][c1] == diff || grid[r2][c1] == diff;
        }
        
        return false;
    }
};