class Solution
{
    public:
        string reverseParentheses(string s)
        {
            // #notes
            stack<char> st;
            int begin = 0, end = s.size() - 1;
            string ans = "", first = "", last = "", str = "";
            for (begin = 0; begin < s.size(); begin++)
            {
                if (s[begin] == '(') break;
                first += s[begin];
            }
            if (begin == s.size()) return first;
            for (; end >= 0; end--)
            {
                if (s[end] == ')') break;
                last = s[end] + last;
            }
            while (begin < end + 1)
            {
                if (s[begin] == ')')
                {
                    str = "";
                    while (!st.empty() && st.top() != '(')
                    {
                        str += st.top();
                        st.pop();
                    }
                    if (!st.empty()) st.pop();
                    for (int k = 0; k < str.size(); k++) st.push(str[k]);
                }
                else st.push(s[begin]);
                begin++;
            }
            while (!st.empty())
            {
                ans = st.top() + ans;
                st.pop();
            }
            return first + ans + last;
        }
};