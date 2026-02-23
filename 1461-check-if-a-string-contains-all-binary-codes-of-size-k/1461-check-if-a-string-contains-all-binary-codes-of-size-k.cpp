class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.size();
        if (len < k)
            return false;
        unordered_set<string> st;
        string sub = "";
        for (int i = 0; i < k; i++)
            sub += s[i];
        st.insert(sub);
        for (int i = k; i < len; i++) {
            sub += s[i];
            sub.erase(sub.begin());
            st.insert(sub);
        }
        return st.size() == (1 << k);
    }
};