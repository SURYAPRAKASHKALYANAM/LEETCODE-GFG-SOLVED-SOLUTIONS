class Solution {
public:
    void generate(int pos, string& s, vector<string>& ans, int len) {
        if (pos == len) {
            ans.emplace_back(s);
            return;
        }
        if (not(s[pos] >= '0' and s[pos] <= '9')) {
            s[pos] ^= 32;
            generate(pos + 1, s, ans, len);
            s[pos] ^= 32;
        }
        generate(pos + 1, s, ans, len);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        generate(0, s, ans, s.size());
        return ans;
    }
};