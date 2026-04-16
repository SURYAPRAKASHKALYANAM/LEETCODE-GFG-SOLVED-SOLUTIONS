class Solution {
public:
    int check(string& s1, int len1, string& s2, int len2,
              vector<vector<int>>& dp) {
        if (len1 < 0 || len2 < 0)
            return 0;
        if (dp[len1][len2] != -1)
            return dp[len1][len2];
        if (s1[len1] == s2[len2])
            return dp[len1][len2] = 1 + check(s1, len1 - 1, s2, len2 - 1, dp);
        return dp[len1][len2] = max(check(s1, len1 - 1, s2, len2, dp),
                                    check(s1, len1, s2, len2 - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int len1 = text1.size() - 1, len2 = text2.size() - 1;
        // return check(text1, len1, text2, len2, dp);
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};