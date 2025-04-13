class Solution {
public:
    int mod = 1e9 + 7;
    long  power(long x, long exp) {
        long  ans = 1;
        long pow = exp;
        while (pow > 0) {
            if (pow & 1) {
                ans = (ans * x) % mod;
                pow = pow - 1;
            } else {
                x = (x * x) % mod;
                pow = pow / 2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long  even = n / 2 + (n % 2), odd = n / 2;
        return (int)((power(5, even) * power(4, odd)) % mod);
    }
};