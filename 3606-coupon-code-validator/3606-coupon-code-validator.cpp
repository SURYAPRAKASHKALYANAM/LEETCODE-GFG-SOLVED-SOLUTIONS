class Solution {
public:
    bool helper(string s) {
        if (s.size() == 0)
            return false;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
                continue;
            else
                return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int len = code.size();
        vector<string> valid(
            {"restaurant", "grocery", "pharmacy", "electronics"});
        vector<string> codes;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int result = businessLine[i].compare(businessLine[j]);
                if (result < 0) {
                    swap(code[i], code[j]);
                    swap(businessLine[i], businessLine[j]);
                    swap(isActive[i], isActive[j]);
                } else if (result == 0) {
                    int result2 = code[i].compare(code[j]);
                    if (result2 < 0) {
                        swap(businessLine[i], businessLine[j]);
                        swap(isActive[i], isActive[j]);
                        swap(code[i], code[j]);
                    }
                }
            }
        }
        for (auto i = 0; i < len; i++) {
            if (isActive[i] &&
                find(valid.begin(), valid.end(), businessLine[i]) !=
                    valid.end() &&
                helper(code[i]))
                codes.emplace_back(code[i]);
        }
        return codes;
    }
};