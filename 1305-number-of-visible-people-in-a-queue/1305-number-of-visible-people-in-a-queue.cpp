class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        int small = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < heights[i]) {
                small++;
                st.pop();
            }
            if (!st.empty())
                small++;
            ans[i] = small;
            st.push(heights[i]);
            small = 0;
        }
        return ans;
    }
};