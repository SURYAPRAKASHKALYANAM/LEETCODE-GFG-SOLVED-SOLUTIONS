class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = n - 1, end;
        string rev = "", sub = "";
        while (start >= 0) {
            while (start >= 0 && s[start] == ' ')
                start--;
            end = start;
            sub = "";
            while (start >= 0 && s[start] != ' ') {
                sub = s[start] + sub;
                start--;
            }
            if ((end - start) >= 1)
                rev += sub + " ";
        }
        rev.pop_back();
        return rev;
    }
};