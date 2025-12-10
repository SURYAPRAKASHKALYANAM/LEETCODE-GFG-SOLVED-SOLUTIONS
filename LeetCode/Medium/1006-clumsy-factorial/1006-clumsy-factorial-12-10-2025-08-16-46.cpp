class Solution {
public:
    int clumsy(int n) {
        if (n <= 3)
            return n * ((n - 1) > 0 ? (n - 1) : 1);
        int stTop = INT_MIN;
        while (n >= 1) {
            if (n <= 3)
                return stTop - (n * ((n - 1) > 0 ? (n - 1) : 1));
            else {
                int val = (n * (n - 1)) / (n - 2);
                if (stTop == INT_MIN) {
                    stTop = val + (n - 3);
                } else {
                    stTop -= val;
                    stTop += (n - 3);
                }
                n -= 4;
            }
        }
        return stTop;
    }
};