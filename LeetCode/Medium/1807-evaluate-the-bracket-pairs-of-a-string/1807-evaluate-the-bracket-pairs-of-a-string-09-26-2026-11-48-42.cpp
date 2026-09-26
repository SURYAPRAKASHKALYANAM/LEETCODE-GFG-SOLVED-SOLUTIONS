class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "", curr = "";
        bool add = true;
        unordered_map<string, string> sMap;
        for (auto known : knowledge)
            sMap[known[0]] = known[1];
        for (char& ch : s) {
            if (ch == '(')
                add = false;
            else if (ch == ')') {
                add = true;
                if (sMap.find(curr) == sMap.end())
                    ans += "?";
                else
                    ans += sMap[curr];
                curr = "";
            } else {
                if (add) {
                    ans += ch;
                } else {
                    curr += ch;
                }
            }
        }
        return ans;
    }
};