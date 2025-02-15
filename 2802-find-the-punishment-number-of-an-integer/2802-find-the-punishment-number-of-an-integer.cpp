class Solution {
public:
    vector<vector<int>> subs;
    int need;
    void partition(int index, vector<int> sub, vector<int> dig) {
        if (index >= dig.size()) {
            subs.emplace_back(sub);
            return;
        }
        int prev = sub.back();
        if (prev > need)
            return;
        sub.emplace_back(dig[index]);
        partition(index + 1, sub, dig);
        sub.pop_back();
        sub.pop_back();
        if (need < (prev * 10 + dig[index]))
            return;
        sub.emplace_back(prev * 10 + dig[index]);
        partition(index + 1, sub, dig);
        sub.pop_back();
    }
    bool helper(int temp, int target) {
        need = target;
        vector<int> dig;
        int digsum = 0;
        while (temp) {
            digsum += (temp % 10);
            dig.insert(dig.begin(), temp % 10);
            temp /= 10;
        }
        if (digsum == target)
            return true;
        vector<int> sub;
        sub.push_back(dig[0]);
        partition(1, sub, dig);
        for (auto subarr : subs) {
            if (accumulate(begin(subarr), end(subarr), 0) == target) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int cnt = 1;
        for (int i = 9; i <= n; i++) {
            if (helper(i * i, i))
                cnt += i * i;
            subs.clear();
        }
        return cnt;
    }
};