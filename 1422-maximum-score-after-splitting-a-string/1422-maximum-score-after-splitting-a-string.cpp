class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ans = 0;
        vector<int> one(n, 0);
        one[n - 1] = (s[n - 1] == '1');
        for (int i = n - 2; i >= 0; i--)
            one[i] = (s[i] == '1') + one[i + 1];
        for (int i = n - 1; i >= 1; i--)
            ans = max(ans, one[i] + i - (one[0] - one[i]));
        return ans;
    }
};