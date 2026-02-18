class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool needOne = (n & 1);
        while (n) {
            if (needOne && !(n & 1))
                return false;
            else if (!needOne && n & 1)
                return false;
            n >>= 1;
            needOne = !needOne;
        }
        return true;
    }
};