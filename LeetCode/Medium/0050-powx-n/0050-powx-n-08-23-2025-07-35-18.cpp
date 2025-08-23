class Solution {
public:
    double myPow(double x, int n) {
        // recursive
        long pow = n;
        if (pow < 0) {
            x = 1 / x;
            pow *= -1;
        }
        if (pow == 0)
            return 1;
        if (pow & 1)
            return x * myPow(x, pow - 1);
        return myPow(x * x, pow / 2);
    }
};