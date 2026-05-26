class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        unordered_set<char> st;
        vector<bool> ban(26, false);
        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                if (ban[ch - 'a'])
                    continue;
                char up = 'A' + (ch - 'a');
                if (st.count(up) && st.count(ch)) {
                    ban[ch - 'a'] = true;
                    cnt--;
                } else if (st.count(ch) == 0) {
                    if (st.count(up)) {
                        ban[ch - 'a'] = true;
                    } else {
                        st.insert(ch);
                    }
                }
            } else {
                if (ban[ch - 'A'])
                    continue;
                char low = 'a' + (ch - 'A');
                if (st.count(low) && st.count(ch) == 0) {
                    cnt++;
                }
                st.insert(ch);
            }
        }
        return cnt;
    }
};