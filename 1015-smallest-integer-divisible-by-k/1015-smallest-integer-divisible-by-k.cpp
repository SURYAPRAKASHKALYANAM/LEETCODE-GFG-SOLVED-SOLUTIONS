class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        if (k == 1)
            return 1;
        long long n = 1LL;
        int cnt = 1;
        while (true) {
            n = (n * 10 + 1) % k;
            cnt++;
            if (n == 0)
                return cnt;
        }
        return cnt;
    }
};