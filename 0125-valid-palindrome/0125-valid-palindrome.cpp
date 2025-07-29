class Solution {
public:
    bool isAlnum(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
               (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int len = s.size();
        int start = 0, end = len - 1;
        while (start < end) {
            while (start < end && !isalnum(s[start]))
                start++;
            while (end > start && !isalnum(s[end]))
                end--;
            if (start < end) {
                if (tolower(s[start]) != tolower(s[end]))
                    return false;
                start++;
                end--;
            } else
                return true;
        }
        return true;
    }
};