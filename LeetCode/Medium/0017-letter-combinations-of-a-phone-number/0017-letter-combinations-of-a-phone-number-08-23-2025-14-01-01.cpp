class Solution {
public:
    unordered_map<char, string> keyMap;
    void generate(int pos, string curr, string& digits, int len,
                  vector<string>& ans) {
        if (len == 0)
            return;
        if (pos == len) {
            ans.emplace_back(curr);
            return;
        }
        for (char i : keyMap[digits[pos]]) {
            generate(pos + 1, curr + i, digits, len, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        // your code goes here
        vector<string> ans;
        keyMap['2'] = "abc";
        keyMap['3'] = "def";
        keyMap['4'] = "ghi";
        keyMap['5'] = "jkl";
        keyMap['6'] = "mno";
        keyMap['7'] = "pqrs";
        keyMap['8'] = "tuv";
        keyMap['9'] = "wxyz";
        generate(0, "", digits, digits.size(), ans);
        return ans;
    }
};