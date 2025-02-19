class Solution {
public:
    void helper(int prev, int curr, string happy, int n, vector<string>& st) {
        prev = curr;
        happy += ('a' + curr);
        if (happy.size() == n) {
            st.push_back(happy);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (prev != i)
                helper(prev, i, happy, n, st);
        }
    }
    string getHappyString(int n, int k) {
        vector<string> st;
        for (int i = 0; i < 3; i++) {
            helper(-1, i, "", n, st);
        }
        sort(st.begin(), st.end());
        return (st.size() >= k) ? st[k - 1] : "";
    }
};