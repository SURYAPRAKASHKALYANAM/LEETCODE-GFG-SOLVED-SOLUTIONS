class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int len = seq.size();
        vector<int> ans(len);
        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (st.empty() || seq[i] == '(') {
                st.push(i);
            } else {
                ans[i] = ans[st.top()] = st.size() & 1;
                st.pop();
            }
        }
        return ans;
    }
};