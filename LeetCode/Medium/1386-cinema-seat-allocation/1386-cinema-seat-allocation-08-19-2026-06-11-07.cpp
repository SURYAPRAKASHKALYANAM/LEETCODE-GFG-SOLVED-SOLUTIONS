class Solution {
public:
    int find(const string& filled) {
        int prefix[10] = {0};
        for (int i = 0; i < 9; ++i)
            prefix[i + 1] = prefix[i] + (filled[i] == '*');

        auto rangeCount = [&](int l, int r) { return prefix[r] - prefix[l]; };

        if (rangeCount(1, 9) == 0)
            return 2;
        if (rangeCount(1, 5) == 0)
            return 1;
        if (rangeCount(3, 7) == 0)
            return 1;
        if (rangeCount(5, 9) == 0)
            return 1;
        return 0;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int cnt = 0;
        int start = 1, ptr = 0, len = reservedSeats.size();
        while (start <= n) {
            string s(10, '#');
            while (ptr < len && start == reservedSeats[ptr][0]) {
                s[reservedSeats[ptr++][1] - 1] = '*';
            }
            cnt += find(s);
            start++;
            if (ptr >= len) {
                cnt += ((n - start + 1) * 2);
                break;
            }
        }
        return cnt;
    }
};