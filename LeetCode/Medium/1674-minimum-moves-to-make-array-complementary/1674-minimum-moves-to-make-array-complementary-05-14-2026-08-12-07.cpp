class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - i - 1];
            if (a > b)
                swap(a, b);
            int min_mv_1 = a + 1;
            int max_mv_1 = b + limit;
            int ex_ma = a + b;

            diff[2] += 2;
            diff[min_mv_1] -= 1;
            diff[max_mv_1 + 1] += 1;

            diff[ex_ma] -= 1;
            diff[ex_ma + 1] += 1;
        }
        int min_moves = n;
        int current_moves = 0;

        for (int target = 2; target <= 2 * limit; target++) {
            current_moves += diff[target];
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;
    }
};