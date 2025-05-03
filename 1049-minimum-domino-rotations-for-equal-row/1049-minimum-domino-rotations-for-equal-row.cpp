class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int minSwap = INT_MAX;
        int n = tops.size();
        for (int ele = 1; ele <= 6; ele++) {
            int tswaps = 0, bswaps = 0;
            for (int i = 0; i < n; i++) {
                if (tops[i] == ele) {
                    tswaps += (bottoms[i] != ele);
                } else if (bottoms[i] == ele) {
                    bswaps += (tops[i] != ele);
                } else {
                    tswaps = bswaps = INT_MAX;
                    break;
                }
            }
            minSwap = min(min(tswaps, bswaps), minSwap);
        }
        return minSwap == INT_MAX ? -1 : minSwap;
    }
};