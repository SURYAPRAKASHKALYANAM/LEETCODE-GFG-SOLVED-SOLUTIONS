class Solution {
public:
    int countVowels(string& s) {
        int cnt = 0;
        set<char> st({'a', 'e', 'i', 'o', 'u'});
        for (char c : s)
            cnt += (st.find(c) != st.end());
        return cnt;
    }
    string reverseWords(string s) {
        string ans = "", sub;
        stringstream ss(s);
        int vCount = 0;
        while (ss >> sub) {
            if (ans.size() == 0) {
                vCount = countVowels(sub);
                ans += sub;
            } else if (countVowels(sub) == vCount) {
                ans += " ";
                reverse(sub.begin(), sub.end());
                ans += sub;
            } else {
                ans += " ";
                ans += sub;
            }
        }
        return ans;
    }
};