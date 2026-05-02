class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> differ(max(10, n + 1), 0), inValid(max(10, n + 1), 0);
        differ[2] = differ[5] = differ[6] = differ[9] = 1;
        inValid[3] = inValid[4] = inValid[7] = 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!inValid[i / 10] && !inValid[i % 10]) {
                if (differ[i / 10] || differ[i % 10]) {
                    differ[i] = 1;
                    cnt++;
                }
            } else {
                inValid[i] = 1;
            }
        }
        return cnt;
    }
};