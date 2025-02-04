class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> after(n), before(n), ans;
        int last = 0;
        after[0] = 0;
        for (int i = 1; i < n; i++) {
            if (security[i - 1] > security[i])
                last = i;
            after[i] = last;
        }
        last = before[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (security[i + 1] > security[i])
                last = i;
            before[i] = last;
        }
        if (after[0] == after[n - 1] && before[0] == before[n - 1] &&
            security[0] != security[n - 1])
            return ans;
        for (int i = time; i + time < n; i++) {
            if (before[i] == before[i - time] && after[i] == after[i + time])
                ans.emplace_back(i);
        }
        return ans;
    }
};