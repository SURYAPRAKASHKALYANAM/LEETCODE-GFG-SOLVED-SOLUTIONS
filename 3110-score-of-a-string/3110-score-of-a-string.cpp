class Solution
{
    public:
        int scoreOfString(string s)
        {
            int scr = 0;
            for (int i = 1; i < s.size(); i++) scr += abs(s[i] - s[i - 1]);
            return scr;
        }
};