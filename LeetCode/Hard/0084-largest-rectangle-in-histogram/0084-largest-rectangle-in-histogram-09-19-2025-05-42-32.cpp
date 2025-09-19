class Solution {
public:
    void findNSE(vector<int>& nse, vector<int>& heights, int& len) {
        stack<int> st;
        for (int i = len - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? len : st.top();
            st.push(i);
        }
    }
    void findPSE(vector<int>& pse, vector<int>& heights, int& len) {
        stack<int> st;
        for (int i = 0; i < len; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> nse(len), pse(len);
        findNSE(nse, heights, len);
        findPSE(pse, heights, len);
        int max_area = 0;
        for (int i = 0; i < len; i++) {
            int width = nse[i] - pse[i] - 1;
            max_area = max(max_area, width * heights[i]);
        }
        return max_area;
    }
};