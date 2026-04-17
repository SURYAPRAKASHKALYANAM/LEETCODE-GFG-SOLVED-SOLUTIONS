class Solution {
   public:
    int compare(int s1, int s2, string& start, string& target, int len1,
                int len2, vector<vector<int>>& dp) {
        if (s1 == len1) return len2 - s2;
        if (s2 == len2) return len1 - s1;
        if (dp[s1][s2] != -1) return dp[s1][s2];
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
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        return compare(0, 0, start, target, len1, len2, dp);
    }
};
