class Solution {
public:
    // bool isvalid(string& s) {
    //     stack<char> st;
    //     for (char ch : s) {
    //         if (ch == ')') {
    //             if (st.empty() || st.top() != '(')
    //                 return false;
    //             st.pop();

    //         } else
    //             st.push(ch);
    //     }
    //     return st.empty();
    // }
    void dfs(vector<string>& ans, int open, int close,string s) {
        if(open==0 && close==0)
        {
            ans.emplace_back(s);
            return;
        }
        if(open>0)
        {
            dfs(ans,open-1,close,s+'(');
        }
        if(close>0)
        {
            if(close>open)
            {
                dfs(ans,open,close-1,s+')');
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        dfs(ans, n, n, s);
        return ans;
    }
};