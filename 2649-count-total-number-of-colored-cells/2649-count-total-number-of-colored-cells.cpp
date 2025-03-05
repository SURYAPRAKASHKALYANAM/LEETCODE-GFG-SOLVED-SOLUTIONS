class Solution {
public:
    long long coloredCells(int n) {
        long long _n = n;
        return 1 + 2 * _n * (_n - 1);
        // long long total = 1, m = 1;
        // for (int i = 1; i < n; i++) {
        //     total += (2 * m) + 2;
        //     m += 2;
        // }
        // return total;
    }
};