class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.size();
        if (len < k)
            return false;
        unordered_set<string> st;
        for (int i = 0; i <= (len - k); i++) {
            string sub = "";
            for (int j = i; j < i + k; j++)
                sub += s[j];
            st.insert(sub);
        }
        return st.size() == (1 << k);
    }
};