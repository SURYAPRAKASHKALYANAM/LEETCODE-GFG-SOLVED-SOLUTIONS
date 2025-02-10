class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        // stack<char> st;

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans.pop_back();
            } else
                ans.push_back(s[i]);
        }
        // while (!st.empty()) {
        // ans = st.top() + ans;
        // st.pop();
        // }
        return ans;
    }
};