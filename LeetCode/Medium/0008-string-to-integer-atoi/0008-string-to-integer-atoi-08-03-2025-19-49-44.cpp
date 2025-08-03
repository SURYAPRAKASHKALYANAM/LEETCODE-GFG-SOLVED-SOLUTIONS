class Solution {
public:
    int myAtoi(string s) {
        bool sign = false, digit = false;
        int num = 0, neg = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (sign || digit)
                    break;
            } else if (s[i] == '+' || s[i] == '-') {
                if (sign || digit)
                    break;
                neg = (s[i] == '-');
                sign = true;
            } else if ((s[i] >= 'a' && s[i] <= 'z') ||
                       (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '.') {
                break;
            } else {
                digit = true;
                num = num * 10 + s[i] - '0';
            }
        }
        return neg ? -num : num;
    }
};