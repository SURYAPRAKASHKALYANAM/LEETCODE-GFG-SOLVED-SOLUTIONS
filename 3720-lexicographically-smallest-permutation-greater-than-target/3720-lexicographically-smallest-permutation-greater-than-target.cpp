class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        multiset<char> st(s.begin(), s.end());
        string res;

        int n = s.size();

        for (int i = 0; i < n; i++) {

            auto it = st.find(target[i]);

            if (it != st.end()) {
                res += target[i];
                st.erase(it);
                continue;
            }
            it = st.upper_bound(target[i]);

            if (it != st.end()) {
                res += *it;
                st.erase(it);

                for (char c : st)
                    res += c;

                return res;
            }

            break;
        }
        for (int j = (int)res.size() - 1; j >= 0; j--) {

            st.insert(res[j]);

            auto it = st.upper_bound(target[j]);

            if (it != st.end()) {

                string ans = res.substr(0, j);
                ans += *it;
                st.erase(it);

                for (char c : st)
                    ans += c;

                return ans;
            }
        }

        return "";
    }
};