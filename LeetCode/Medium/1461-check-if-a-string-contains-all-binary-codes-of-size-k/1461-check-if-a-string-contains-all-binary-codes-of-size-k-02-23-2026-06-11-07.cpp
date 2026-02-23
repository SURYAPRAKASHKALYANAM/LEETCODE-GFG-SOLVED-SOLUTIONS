class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int len = s.size();
        for (int i = 0; i <= (len - k); i++) {
            string sub = "";
            for (int j = i; j < i + k; j++)
                sub += s[j];
            st.insert(sub);
        }
        return st.size() == (1 << k);
    }
};