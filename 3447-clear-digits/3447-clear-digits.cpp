class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                st.pop();
            } else
                st.push(s[i]);
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};