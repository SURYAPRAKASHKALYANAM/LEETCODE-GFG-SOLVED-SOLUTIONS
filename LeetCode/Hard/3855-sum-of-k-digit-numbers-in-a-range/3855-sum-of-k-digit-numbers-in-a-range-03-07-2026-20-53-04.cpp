class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1LL;
        while (exp) {
            if (exp & 1) {
                exp--;
                res = (res * base) % mod;
            } else {
                base = (base * base) % mod;
                exp /= 2;
            }
        }
        return res % mod;
    }
    int sumOfNumbers(int l, int r, int k) {
        long long sum = (r + 1) * (r) / 2;
        if (l > 0)
            sum -= (l * (l - 1) / 2);
        long long mod = 1e9 + 7;
        long long ways = power(r - l + 1, k - 1, mod);
        long long num = (power(10, k, mod) - 1 + mod) % mod;
        long long denInv = power(9, mod - 2, mod);
        long long geomSum = (num * denInv) % mod;
        long long ans = (sum * ways) % mod;
        ans = (ans * geomSum) % mod;
        return ans % mod;
    }
};