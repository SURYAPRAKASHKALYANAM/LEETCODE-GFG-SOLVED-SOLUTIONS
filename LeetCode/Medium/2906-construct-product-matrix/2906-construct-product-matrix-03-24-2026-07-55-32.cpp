class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 12345;
        vector<vector<int>> ans(n, vector<int>(m));
        
        long long prod = 1;
        for (int i = 0; i < n * m; i++) {
            int row = i / m;
            int col = i % m;
            ans[row][col] = prod; 
            prod = (prod * grid[row][col]) % mod; 
        }
        

        prod = 1;
        for (int i = n * m - 1; i >= 0; i--) {
            int row = i / m;
            int col = i % m;
            ans[row][col] = (ans[row][col] * prod) % mod; 
            prod = (prod * grid[row][col]) % mod; 
        }
        
        return ans;
    }
};