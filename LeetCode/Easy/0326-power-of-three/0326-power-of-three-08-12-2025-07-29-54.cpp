class Solution {
public:
    int helper(long long val, long long pow, long long res) {
        long long ans = 1;
        while (pow) {
            if (pow % 2) {
                ans *= val;
                if (ans > res)
                    return 2;
                pow--;
            } else {
                val *= val;
                if (val > res)
                    return 2;
                pow /= 2;
            }
        }
        return ans == res;
    }
    bool isPowerOfThree(int n) {
        int start = 0, end = n;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = helper(3, mid, n);
            if (val == 1)
                return true;
            else if (val == 2)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};