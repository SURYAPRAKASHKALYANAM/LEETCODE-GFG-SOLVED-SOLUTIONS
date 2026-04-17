class Solution {
public:
    int compare(int s1, int s2, string& start, string& target, int len1,
                int len2, vector<vector<int>>& dp) {
        if (s1 == len1)
            return len2 - s2;
        if (s2 == len2)
            return len1 - s1;
        if (dp[s1][s2] != -1)
            return dp[s1][s2];
        if (start[s1] == target[s2])
            return dp[s1][s2] =
                       compare(s1 + 1, s2 + 1, start, target, len1, len2, dp);
        int deletePres = 1 + compare(s1 + 1, s2, start, target, len1, len2, dp);
        int insert = 1 + compare(s1, s2 + 1, start, target, len1, len2, dp);
        int replace =
            1 + compare(s1 + 1, s2 + 1, start, target, len1, len2, dp);
        return dp[s1][s2] = min({deletePres, insert, replace});
    }
    int minDistance(string start, string target) {
        int len1 = start.size(), len2 = target.size();
        // vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        // return compare(0, 0, start, target, len1, len2, dp); top down

        // bottom up
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (start[i - 1] == target[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }
        return dp[len1][len2];
    }
};
