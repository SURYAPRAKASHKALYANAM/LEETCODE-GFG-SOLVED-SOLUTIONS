class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (auto i : s) {
            if (i == '*') {
                if (res.size())
                    res.pop_back();
            } else if (i == '#')
                res += res;
            else if (i == '%')
                reverse(res.begin(), res.end());
            else
                res += i;
        }
        return res;
    }
};