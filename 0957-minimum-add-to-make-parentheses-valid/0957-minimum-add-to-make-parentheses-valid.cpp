class Solution
{
    public:
        int minAddToMakeValid(string s)
        {
            int cnt = 0,leftover=0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(') cnt++;
                else cnt>0?cnt--:leftover++;
            }
            return leftover+cnt;
        }
};