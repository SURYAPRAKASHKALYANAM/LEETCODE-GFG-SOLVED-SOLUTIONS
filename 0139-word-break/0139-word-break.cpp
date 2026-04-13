class Solution {
public:
    bool backtrack(int idx, string& s, unordered_map<string, bool>& availWords,
                   vector<int>& memo) {
        if (idx >= s.size())
            return true;
        if (memo[idx] != -1)
            return memo[idx];
        for (int i = idx; i < s.size(); i++) {
            if (availWords[s.substr(idx, i - idx + 1)]) {
                if (backtrack(i + 1, s, availWords, memo)) {
                    return memo[idx] = true;
                }
            }
        }

        return memo[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // Your code goes here
        unordered_map<string, bool> availWords;
        vector<int> memo(s.size(), -1);
        for (string& str : wordDict)
            availWords[str] = true;
        return backtrack(0, s, availWords, memo);
    }
};