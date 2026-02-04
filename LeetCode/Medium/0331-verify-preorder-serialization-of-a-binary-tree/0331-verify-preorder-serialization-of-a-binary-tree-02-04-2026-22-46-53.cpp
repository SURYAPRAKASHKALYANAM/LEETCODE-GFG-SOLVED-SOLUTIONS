class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 1)
            return preorder == "#";
        stringstream ss(preorder);
        string sub;
        vector<string> strs;
        while (getline(ss, sub, ','))
            strs.push_back(sub);
        vector<string> st;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            st.push_back(str);
            while (st.size() >= 3) {
                if (st[st.size() - 1] == "#" && st[st.size() - 2] == "#" &&
                    st[st.size() - 3] != "#") {
                    st.pop_back();
                    st.pop_back();
                    st.pop_back();
                    if (i != strs.size() - 1 || st.size())
                        st.push_back("#");
                } else
                    break;
            }
        }
        return st.size() == 0;
    }
};