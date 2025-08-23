class Solution {
public:
    bool palindrome(int start, int end, string& s) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void generate(int pos, string& s, int len, vector<vector<string>>& ans,
                  vector<string>& sub) {
        if (pos >= len) {
            ans.emplace_back(sub);
            return;
        }
        for (int i = pos; i < len; i++) {
            if (palindrome(pos, i, s)) {
                sub.emplace_back(s.substr(pos, (i - pos + 1)));
                generate(i + 1, s, len, ans, sub);
                sub.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // your code goes here
        vector<vector<string>> ans;
        vector<string> sub;
        generate(0, s, s.size(), ans, sub);
        return ans;
    }
};