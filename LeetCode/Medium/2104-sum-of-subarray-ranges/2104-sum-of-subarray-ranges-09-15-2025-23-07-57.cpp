class Solution {
public:
    void findNSE(vector<int>& nse, vector<int>& nums, int& n) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void findPSEE(vector<int>& psee, vector<int>& nums, int& n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    void findNGE(vector<int>& nge, vector<int>& nums, int& n) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void findPGEE(vector<int>& pgee, vector<int>& nums, int& n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, 0), psee(n, 0), nge(n, 0), pgee(n, 0);
        findNSE(nse, nums, n);
        findPSEE(psee, nums, n);
        findNGE(nge, nums, n);
        findPGEE(pgee, nums, n);
        long long sum = 0LL;
        for (int i = 0; i < n; i++) {
            int sLeft = i - psee[i];
            int sRight = nse[i] - i;
            int aLeft = i - pgee[i];
            int aRight = nge[i] - i;
            sum +=
                (aLeft * aRight * 1LL - sLeft * sRight * 1LL) * 1LL * nums[i];
        }
        return sum;
    }
};