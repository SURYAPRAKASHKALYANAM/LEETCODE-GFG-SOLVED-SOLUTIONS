// Haha 
//const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
// #define LC_HACK
// #ifdef LC_HACK
// const auto __ = []() {
//     struct ___ {
//         static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
//     };
//     std::atexit(&___::_);
//     return 0;
// }();
// #endif
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> merged;
        for (auto i : meetings) {
            if (merged.empty()) {
                merged.push_back(i);
            } else {
                if (merged.back()[1] >= i[0]) {
                    merged.back()[1] = max(merged.back()[1], i[1]);
                } else
                    merged.push_back(i);
            }
        }
        int cnt = merged[0][0] - 1;
        for (int i = 1; i < merged.size(); i++) {
            cnt += merged[i][0] - (merged[i - 1][1] + 1);
        }
        cnt += days - (merged.back()[1]);
        return cnt;
    }
};