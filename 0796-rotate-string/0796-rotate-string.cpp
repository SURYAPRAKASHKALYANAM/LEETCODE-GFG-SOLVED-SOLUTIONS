class Solution
{
    public:
    bool match(string s, string goal, int i)
    {
        int start = 0;
        while (start < goal.size())
        {
            if (goal[start] != s[i]) return false;
            start++, i++;
            if (i == s.size()) i = 0;
        }
        return true;
    }
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size()) return false;
        bool ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == goal[0]) ans |= match(s, goal, i);
        }
        return ans;
    }
};