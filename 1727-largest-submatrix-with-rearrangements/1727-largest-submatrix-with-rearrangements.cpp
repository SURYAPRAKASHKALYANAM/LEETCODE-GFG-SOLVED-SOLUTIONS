class Solution {
public:
    void findNSE(vector<int>& nse, vector<int>& bar, int& len) {
        stack<int> st;
        for (int i = len - 1; i >= 0; i--) {
            while (!st.empty() && bar[st.top()] >= bar[i])
                st.pop();
            nse[i] = st.empty() ? len : st.top();
            st.push(i);
        }
    }
    void findPSE(vector<int>& pse, vector<int>& bar, int& len) {
        stack<int> st;
        for (int i = 0; i < len; i++) {
            while (!st.empty() && bar[st.top()] >= bar[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int findMax(vector<int>& bar, int& len) {
        vector<int> nse(len), pse(len);
        findNSE(nse, bar, len);
        findPSE(pse, bar, len);
        int max_a = 0;
        for (int i = 0; i < len; i++) {
            int w = nse[i] - pse[i] - 1;
            max_a = max(max_a, w * bar[i]);
        }
        return max_a;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j])
                    matrix[i][j] += matrix[i - 1][j];
            }
        }
        int max_area = 0;
        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end());
            max_area = max(max_area, findMax(matrix[i], n));
        }
        return max_area;
    }
};