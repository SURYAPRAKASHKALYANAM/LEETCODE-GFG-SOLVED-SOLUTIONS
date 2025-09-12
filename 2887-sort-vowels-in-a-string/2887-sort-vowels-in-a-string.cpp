class Solution {
public:
    string sortVowels(string s) {
        set<char> st({'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'});
        string res = "";
        for (auto i : s) {
            if (st.count(i))
                res += i;
        }
        if (res == "")
            return s;
        sort(res.begin(), res.end());
        int pos = 0;
        for (auto& i : s) {
            if (st.count(i)) {
                i = res[pos++];
            }
        }
        return s;
    }
};