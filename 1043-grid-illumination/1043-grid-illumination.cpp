class Solution {
public:
    unordered_map<long long, long long> row, col, dia1, dia2, isLamp;
    void turn(long long r, long long c, bool On, long long n) {
        if (On) {
            row[r]++;
            col[c]++;
            dia1[n + (c - r)]++;
            dia2[r + c]++;
        } else {
            // if (rows[r])
            row[r]--;
            // if (col[c])
            col[c]--;
            dia1[n + (c - r)]--;
            dia2[r + c]--;
        }
    }
    int isIlluminated(long long r, long long c, long long n) {
        return row[r] >= 1 || col[c] >= 1 || dia1[n + (c - r)] >= 1 ||
               dia2[r + c] >= 1;
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {

        for (auto i : lamps) {
            if (!isLamp[(long long)n * i[0] + i[1]])
                turn(i[0], i[1], true, n);
            isLamp[(long long)n * i[0] + i[1]] = 1;
        }
        vector<int> ans;
        for (auto q : queries) {
            ans.emplace_back(isIlluminated(q[0], q[1], n));
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int r = i + q[0], c = j + q[1];
                    if (r >= 0 && r < n && c >= 0 && c < n &&
                        isLamp[(long long)n * r + c]) {
                        turn(r, c, false, n);
                        isLamp[(long long)n * r + c] = 0;
                    }
                }
            }
        }
        return ans;
    }
};