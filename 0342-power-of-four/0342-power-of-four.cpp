class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        if (n % 4 != 0)
            return false;
        while (n > 0) {
            n = n / 4;
            if (n == 1)
                return true;
            else if (n % 4 != 0)
                return false;
        }
        return false;
    }
};