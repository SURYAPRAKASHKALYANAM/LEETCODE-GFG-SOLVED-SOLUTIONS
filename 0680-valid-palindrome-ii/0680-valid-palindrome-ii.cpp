class Solution {
public:
    bool isPalindrome(int start, int end, string s) {
        while (start < end) {
            if (s[end] != s[start])
                return false;
            end--;
            start++;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                if (s[start] == s[end - 1] || s[start + 1] == s[end]) {
                    return isPalindrome(start + 1, end, s) ||
                           isPalindrome(start, end - 1, s);
                } else
                    return false;
            }
            start++;
            end--;
        }
        return true;
    }
};