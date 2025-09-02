class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0, k = 1;
        int maxi = max(start, goal);
        while (k <= maxi) {
            if ((k & start) != (k & goal))
                cnt++;
            k <<= 1;
        }
        return cnt;
    }
};