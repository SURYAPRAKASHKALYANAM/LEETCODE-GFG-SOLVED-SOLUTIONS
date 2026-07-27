class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 <= num2)
            return -1;
        if (num1 == num2)
            return 0;
        for (long long i = 1LL; i <= 60LL; i++) {
            long long left = (num1 - i * num2);
            if (left > 0 && setbits(left) <= i && i <= left)
                return i;
        }
        return -1;
    }
    int setbits(long long n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1LL);
            cnt++;
        }
        return cnt;
    }
};