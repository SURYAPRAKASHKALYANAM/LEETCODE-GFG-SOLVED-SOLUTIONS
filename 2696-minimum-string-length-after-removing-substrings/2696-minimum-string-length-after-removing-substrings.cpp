class Solution
{
    public:
        int minLength(string s)
        {
            stack<char> st;
            int cnt = 0;
            for (auto i: s)
            {
                if (st.empty()) st.push(i);
                else if (i == 'B' && st.top() == 'A') cnt++, st.pop();
                else if (i == 'D' && st.top() == 'C') cnt++, st.pop();
                else st.push(i);
            }
            return s.size() - cnt * 2;
        }
};