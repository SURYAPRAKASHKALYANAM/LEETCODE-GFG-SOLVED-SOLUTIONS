class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long maxPrefix = 0, minPrefix = 0, prefSum = 0;
        for (int d : differences) {
            prefSum += d;
            maxPrefix = max(maxPrefix, prefSum);
            minPrefix = min(minPrefix, prefSum);
        }
        return max(0, (int)((upper - maxPrefix) - (lower - minPrefix) + 1));
    }
};