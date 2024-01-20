class Solution
{
    public:
        int myAtoi(string s)
        {
            long long n = 0;
            string req = "";
            bool pos = 1, find_digit = false, find_sign = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (find_sign)
                {
                    if (s[i] == '+' || s[i] == '-' || s[i]==' ') break;
                }
                if (s[i] == '+' || s[i] == '-') find_sign = 1;
                if (s[i] == '-' && !find_digit) pos = 0;
                if (s[i] >= '0' && s[i] <= '9')
                {
                    req += s[i];
                    find_digit = true;
                }
                else
                {
                    if (!find_digit && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '.')) return 0;
                    if (find_digit) break;
                }
            }
            for (int i = 0; i < req.size(); i++)
            {
                n = n *10 + (req[i] - '0');
                if (pos)
                {
                    if (n > pow(2, 31) - 1) return pow(2, 31) - 1;
                }
                else
                {
                    n *= -1;
                    if (n <= pow(-2, 31)) return pow(-2, 31);
                    n *= -1;
                }
            }
            return (pos) ? (int) n : -(int) n;
        }
};