class Solution {
public:
    char findTheDifference(string s, string t) {
        if (s.size() == 0)
            return t[0];
        int c = s[0] - 'a';
        for (int i = 1; i < s.size(); i++)
            c ^= (s[i] - 'a');
        for (int i = 0; i < t.size(); i++)
            c ^= (t[i] - 'a');
        return 'a' + c;
    }
};