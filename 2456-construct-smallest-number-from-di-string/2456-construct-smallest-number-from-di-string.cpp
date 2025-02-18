class Solution {
public:
    bool helper(int curr, int pos, string& final, string& pattern,
                vector<int> used, int n) {
        if (curr <= 0 || curr > 9)
            return false;
        used[curr] = 1;
        final += to_string(curr);
        if (pos == n)
            return true;
        if (pattern[pos] == 'I') {
            for (int i = curr + 1; i <= 9; i++) {
                if (!used[i]) {
                    if (helper(i, pos + 1, final, pattern, used, n))
                        return true;
                }
            }
        } else {
            for (int i = curr - 1; i >= 1; i--) {
                if (!used[i]) {
                    if (helper(i, pos + 1, final, pattern, used, n))
                        return true;
                }
            }
        }
        final.pop_back();
        used[curr] = 0;
        return false;
    }
    string smallestNumber(string pattern) {
        vector<int> used(10, 0);
        string final = "";
        int n = pattern.size();
        for (auto i = 1; i <= 9; i++) {
            if (helper(i, 0, final, pattern, used, n))
                break;
        }
        return final;
    }
};

/*
for (int i = curr; i <= 9; i++) {
            if (!used[i]) {
                used[i] = 1;
                if (pattern[pos] == 'I') {
                    final += to_string(i);
                    if (helper(i + 1, pos + 1, final, pattern, used, n))
                        return true;
                    final.pop_back();
                } else {
                    final += to_string(i);
                    if (helper(i - 1, pos + 1, final, pattern, used, n))
                        return true;
                    final.pop_back();
                }

                used[i] = 0;
            }
        }
        */