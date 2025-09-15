class Solution {
public:
    void findNSE(vector<int>& nse, vector<int>& arr, int& n) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void findPSEE(vector<int>& pse, vector<int>& arr, int& n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> nse(n), pse(n);
        findNSE(nse, arr, n);
        findPSEE(pse, arr, n);
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + ((long)arr[i] * (nse[i] - i) * (i - pse[i])) % mod) %
                  mod;
        }
        return sum;
    }
};
