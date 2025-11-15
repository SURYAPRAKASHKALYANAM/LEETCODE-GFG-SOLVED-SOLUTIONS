class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int len = colors.size(), ans = 0;
        int prevC = colors[0] - 'a', prevS = neededTime[0],
            maxPrev = neededTime[0];
        for (int i = 1; i < len; i++) {
            if (prevC != (colors[i] - 'a')) {
                ans += (prevS - maxPrev);
                prevC = colors[i] - 'a', prevS = neededTime[i],
                maxPrev = neededTime[i];
            } else {
                prevS += neededTime[i];
                maxPrev = max(neededTime[i], maxPrev);
            }
        }
        ans += (prevS - maxPrev);
        return ans;
    }
};