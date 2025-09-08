class Solution {
public:
    bool check(string& s, int pos, int cnt, vector<vector<int>>& dp) {
        if (pos == s.size())
            return cnt == 0;
        if (cnt < 0)
            return false;
        if (dp[pos][cnt] != -1)
            return false;
        if (s[pos] == '(')
            return dp[pos][cnt] = check(s, pos + 1, cnt + 1, dp);
        else if (s[pos] == ')')
            return dp[pos][cnt] = check(s, pos + 1, cnt - 1, dp);
        return dp[pos][cnt] = check(s, pos + 1, cnt + 1, dp) ||
                              check(s, pos + 1, cnt - 1, dp) ||
                              check(s, pos + 1, cnt, dp);
    }
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return check(s, 0, 0, dp);
    }
};