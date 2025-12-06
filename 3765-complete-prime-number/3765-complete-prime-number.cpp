class Solution {
public:
    bool check(int n) {
        if (n == 1)
            return false;
        for (int i = 2; (i * i) <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    bool completePrime(int num) {
        int len = log10(num);
        int d = pow(10, len);
        while (d) {
            if (!check(num / d))
                return false;
            d /= 10;
        }
        d = 10;
        int cnt = 0;
        while (cnt <= len) {
            if (!check(num % d))
                return false;
            d *= 10;
            cnt++;
        }
        return true;
    }
};