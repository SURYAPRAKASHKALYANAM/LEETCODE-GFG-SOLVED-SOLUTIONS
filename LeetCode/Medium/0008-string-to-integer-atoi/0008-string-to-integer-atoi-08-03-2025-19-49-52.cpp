class Solution {
public:
    int myAtoi(string s) {
        bool sign = false, digit = false;
        long num = 0;
        bool neg = false;
        int highint = pow(2,31)-1;
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
                num = num * 10L + s[i] - '0';
                if(num>highint) {
                    num = highint;
                    if(neg) num++;
                    break;
                }
            }
        }
        return neg ? -num : num;
    }
};