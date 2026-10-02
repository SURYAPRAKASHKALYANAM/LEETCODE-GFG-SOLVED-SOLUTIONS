class Solution {
   public:
    void generate(vector<string>& ans, string curr, int open, int close,
                  int len) {
        if (open < close) return;
        if (open + close == 2 * len) {
            ans.emplace_back(curr);
            return;
        }
        if (open < len) generate(ans, curr + '(', open + 1, close, len);
        if (close < len) generate(ans, curr + ')', open, close + 1, len);
    }
    vector<string> generateParenthesis(int n) {
        // your code goes here
        vector<string> ans;
        generate(ans, "", 0, 0, n);
        return ans;
    }
};