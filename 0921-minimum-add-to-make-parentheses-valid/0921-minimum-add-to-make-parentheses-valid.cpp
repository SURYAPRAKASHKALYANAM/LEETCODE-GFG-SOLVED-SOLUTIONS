class Solution
{
    public:
        int minAddToMakeValid(string s)
        {
            stack<char> st;
            for (auto i: s)
            {
                if (i == ')')
                {
                    if (!st.empty() && st.top() == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
            return st.size();
        }
};