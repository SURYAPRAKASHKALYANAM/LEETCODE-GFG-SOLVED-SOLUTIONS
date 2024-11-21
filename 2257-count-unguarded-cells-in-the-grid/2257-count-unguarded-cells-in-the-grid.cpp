class Solution
{
    public:
        void find(vector<vector < int>> &nums, int row, int col, int m, int n,int dx,int dy)
        {
            if (row < 0 || row >= m) return;
            if (col < 0 || col >= n) return;
            if (nums[row][col] <0) return;
            nums[row][col] = 0;
            find(nums, row +dx , col+dy, m, n,dx,dy);
        }
    int countUnguarded(int m, int n, vector<vector < int>> &guards, vector< vector< int>> &walls)
    {
        vector<vector < int>> nums(m, vector<int> (n, 1));
        for (auto i: guards) nums[i[0]][i[1]] = -1;
        for (auto i: walls) nums[i[0]][i[1]] = -2;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i][j] == -1)
                {
                    nums[i][j] = 3;
                    find(nums, i, j, m, n,-1,0);
                    find(nums, i, j, m, n,1,0);
                    find(nums, i, j, m, n,0,-1);
                    find(nums, i, j, m, n,0,+1);
                    nums[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};