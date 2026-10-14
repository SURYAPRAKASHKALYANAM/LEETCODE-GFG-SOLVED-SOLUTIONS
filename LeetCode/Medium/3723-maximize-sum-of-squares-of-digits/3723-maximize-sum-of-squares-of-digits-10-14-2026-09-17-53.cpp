class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for (int i = 0; i < num; i++) {
            for (int i = 9; i >= 0; i--) {
                if (sum >= i) {
                    sum -= i;
                    ans += (i + '0');
                    break;
                }
            }
        }
        return sum != 0 ? "" : ans;
    }
};