// class Solution {
// public:
//     int find(const string& filled) {
//         int prefix[10] = {0};
//         for (int i = 0; i < 9; ++i)
//             prefix[i + 1] = prefix[i] + (filled[i] == '*');

//         auto rangeCount = [&](int l, int r) { return prefix[r] - prefix[l]; };

//         if (rangeCount(1, 9) == 0)
//             return 2;
//         if (rangeCount(1, 5) == 0)
//             return 1;
//         if (rangeCount(3, 7) == 0)
//             return 1;
//         if (rangeCount(5, 9) == 0)
//             return 1;
//         return 0;
//     }
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//         sort(reservedSeats.begin(), reservedSeats.end());
//         int cnt = 0;
//         int start = 1, ptr = 0, len = reservedSeats.size();
//         while (start <= n) {
//             string s(10, '#');
//             while (ptr < len && start == reservedSeats[ptr][0]) {
//                 s[reservedSeats[ptr++][1] - 1] = '*';
//             }
//             cnt += find(s);
//             start++;
//             if (ptr >= len) {
//                 cnt += ((n - start + 1) * 2);
//                 break;
//             }
//         }
//         return cnt;
//     }
// };
// optimal
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;   
        rowMask.reserve(reservedSeats.size());

        for (auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            if (col >= 2 && col <= 9)
                rowMask[row] |= (1 << (col - 1));
        }

        constexpr int LEFT  = 0b0000011110;  
        constexpr int MID   = 0b0001111000;  
        constexpr int RIGHT = 0b0111100000;  

        long long total = 2LL * n;            
        for (auto& [row, mask] : rowMask) {
            total -= 2;                       
            if (!(mask & LEFT) && !(mask & RIGHT))
                total += 2;
            else if (!(mask & LEFT) || !(mask & MID) || !(mask & RIGHT))
                total += 1;
        }
        return (int)total;
    }
};