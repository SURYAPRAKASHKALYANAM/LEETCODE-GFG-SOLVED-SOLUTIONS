class Solution {
public:
    void helper(int prev, int curr, string happy, int n, set<string>& st) {
        if (prev == curr || happy.size() > n)
            return;
        prev = curr;
        happy += ('a' + curr);
        if (happy.size() == n) {
            st.insert(happy);
        }
        for (int i = 0; i < 3; i++) {
            helper(prev, i, happy, n, st);
        }
    }
    string getHappyString(int n, int k) {
        set<string> st;
        for (int i = 0; i < 3; i++) {
            helper(-1, i, "", n, st);
        }
        for (auto i : st) {
            if (--k == 0)
                return i;
        }
        return "";
    }
};