class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<string> st;
        string ans = "";
        int pos = 0, n = s.size();
        while (pos < n) {
            if (s[pos] == ')') {
                string sub = "";
                bool found = false;
                while (!st.empty()) {
                    sub = st.top() + sub;
                    if (st.top() == "(") {
                        st.pop();
                        found = true;
                        break;
                    }
                    st.pop();
                }
                if (found) {
                    sub += s[pos];
                }
                st.push(sub);
            } else {
                st.push(string(1, s[pos]));
            }
            pos++;
        }
        while (!st.empty()) {
            if(st.top()!="(")
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};