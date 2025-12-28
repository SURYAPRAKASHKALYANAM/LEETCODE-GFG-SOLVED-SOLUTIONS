class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        long long limit = LONG_MAX;
        int dig = log10(k), cnt = dig + 1;
        long long n = 1;
        while (dig) {
            n *= 10;
            n += 1;
            dig--;
        }
        unordered_map<int, int> seen;
        while (n < limit) {
            if (n % k == 0)
                break;
            n *= 10;
            n += 1;
            n %= k;
            cnt++;
            if (seen[n])
                return -1;
            seen[n] = 1;
        }
        return cnt;
    }
};