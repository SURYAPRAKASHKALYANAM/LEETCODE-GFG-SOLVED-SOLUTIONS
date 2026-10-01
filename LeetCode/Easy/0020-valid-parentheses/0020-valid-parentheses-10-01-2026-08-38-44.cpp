class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            } else if (!st.empty()) {
                if (i == ')' && st.top() == '(') {
                    st.pop();
                } else if (i == '}' && st.top() == '{') {
                    st.pop();
                } else if (st.top() == '[' && i == ']') {
                    st.pop();
                } else
                    break;
            } else {
                return false;
            }
        }
        return st.empty();
    }
};