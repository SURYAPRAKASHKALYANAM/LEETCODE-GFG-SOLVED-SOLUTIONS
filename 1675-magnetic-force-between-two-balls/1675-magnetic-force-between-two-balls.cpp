class Solution {
public:
    bool canPossible(int gap, vector<int>& position, int len, int m) {
        int can = 1, lastPicked = 0;
        for (int i = 1; i < len; i++) {
            if (position[i] - position[lastPicked] >= gap) {
                can++;
                lastPicked = i;
            }
            if (can == m)
                break;
        }
        return can == m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int start = 1, end = position.back() - position.front();
        int mid, len = position.size(), ans = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (canPossible(mid, position, len, m)) {
                ans = max(mid, ans);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};